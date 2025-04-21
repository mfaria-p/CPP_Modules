#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <algorithm>
#include <deque>
#include <vector>
class PmergeMe
{
  public:
    PmergeMe();
    PmergeMe(const PmergeMe& pm);
    PmergeMe& operator=(const PmergeMe& pm);
    ~PmergeMe();

    void SortVec(std::vector<int>& vec);
    void SortDeque(std::deque<int>& deque);

  private:
    template <typename T> void MergeInsertSort(T& container, int pair_level);

    template <typename T> void PairSwap(T it, int pair_level);
};

int _jacobsthal_nbr(int n);

template <typename T> T next(T it, int steps)
{
    std::advance(it, steps);
    return it;
}

template <typename T> void PmergeMe::PairSwap(T it, int pair_level)
{
    //start points to the start of the first unit
    T start = next(it, -pair_level + 1);
    //end points just past the first unit
    T end = next(start, pair_level);
    while (start != end)
    {
        std::iter_swap(start, next(start, pair_level));
        start++;
    }
}

template <typename T> bool Compare(T lv, T rv) 
{
	return *lv < *rv;
}

template <typename T> void PmergeMe::MergeInsertSort(T& container, int pair_level)
{
    typedef typename T::iterator Iterator;
    //Each unit is pair_level long

    // Check if the number of partitions
    int pair_units_nbr = container.size() / pair_level;

    //If there is an odd pair, we ignore it during swapping.
    //It will go to the pend as the last pair. */
    bool is_odd = pair_units_nbr % 2 == 1;

    if (pair_units_nbr < 2)
        return;
    
    /* It's important to caluclate the end position until which we should iterate.
    We can have a set of values like:
    ((1 2) (3 4)) ((3 8) (2 6)) | 0
    where there are numbers (0 in this case) which can't even form a pair.
    Those values should be ignored. */

    Iterator start = container.begin();

    //last covers all elements that could possibly be in a pair, even the unpaired one at the end
    Iterator last = next(container.begin(), pair_level * (pair_units_nbr));

    //If is_odd == 1 → go back by pair_level to exclude the unpaired one from the loop
    //So end marks where the main loop should stop
    Iterator end = next(last, -(is_odd * pair_level));

   /*STEP 1: Swap pairs of numbers, pairs, pairs of pairs etc by the biggest pair
    number. After each swap we recurse. This step operates on its own! */
    int jump = 2 * pair_level;
    for (Iterator it = start; it != end; std::advance(it, jump))
    {
    //this_pair: points to the last element of the first unit
        Iterator this_pair = next(it, pair_level - 1);
    //next_pair: points to the last element of the second unit
        Iterator next_pair = next(it, pair_level * 2 - 1);
        if (*next_pair < *this_pair)
        {
            PairSwap(this_pair, pair_level);
        }
    }
    //when the pair_units_nbr < 2, the "recursion ends", theres no more recursion levels, and it goes to the next step 
    //(both next steps are made in the reversed order, which means it starts in the bigger recursion order, and goes to the smaller one)
    MergeInsertSort(container, pair_level * 2);

    //STEP": Initialization
    //Main will contain an already sorted sequence
    //Pend stores a yet to be sorted numbers.
    std::vector<Iterator> main;
    std::vector<Iterator> pend;

    //Initialize the main chain with the {b1, a1}.
    //The first b value (the smaller in the first pair)
    main.insert(main.end(), next(container.begin(), pair_level - 1));
    //The first a value (the larger in the first pair, already sorted in previous steps)
    main.insert(main.end(), next(container.begin(), pair_level * 2 - 1));

    //Insert the rest of a's into the main chain.
    //Insert the rest of b's into the pend.
    for (int i = 4; i <= pair_units_nbr; i += 2)
    {
      //Example: pair_level = 1, para i=4: 
      //1 * (4 - 1) - 1 = 2; container[2]=b2, because it is b1, a1, b2, a2, ...
      pend.insert(pend.end(), next(container.begin(), pair_level * (i - 1) - 1));
      //1 * 4 - 1 = 3; container[3]=b2, because it is b1, a1, b2, a2, ...
      main.insert(main.end(), next(container.begin(), pair_level * i - 1));
    }

    //Insert an odd element to the pend, if there are any.
    if (is_odd)
    {
        pend.insert(pend.end(), next(end, pair_level - 1));
    }

    /* Insert the pend into the main in the order determined by the
    Jacobsthal numbers. For example: 3 2 -> 5 4 -> 11 10 9 8 7 6 -> etc.
    During insertion, main numbers serve as an upper bound for inserting numbers,
    in order to save number of comparisons, as we know already that, for example,
    b5 is lesser than a5, we binary search only until a5, not until the end
    of the container. */
    int prev_jacobsthal = _jacobsthal_nbr(1);
    int inserted_numbers = 0;
    for (int k = 2;; k++)
    {
      int curr_jacobsthal = _jacobsthal_nbr(k);
      int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
      int offset = 0;
      if (jacobsthal_diff > static_cast<int>(pend.size()))
          break;
      int nbr_of_times = jacobsthal_diff;
      typename std::vector<Iterator>::iterator pend_it = next(pend.begin(), jacobsthal_diff - 1);
      typename std::vector<Iterator>::iterator bound_it =
          next(main.begin(), curr_jacobsthal + inserted_numbers);
      while (nbr_of_times)
      {
        typename std::vector<Iterator>::iterator idx =
            std::upper_bound(main.begin(), bound_it, *pend_it, Compare<Iterator>);
        typename std::vector<Iterator>::iterator inserted = main.insert(idx, *pend_it);
        nbr_of_times--;
        pend_it = pend.erase(pend_it);
        std::advance(pend_it, -1);
        /* Sometimes the inserted number in inserted at the exact index of where the bound should be.
        When this happens, it eclipses the bound of the next pend, and it does more comparisons
        than it should. We need to offset when this happens. */
        //Before:
        //main:    [a1 a2 a3 a4 a5 _ _ _ ... ]
        //         |           |
        //      inserted       bound

        //Insert b5 → right at `bound`.

        //Now:
        //main:    [a1 a2 a3 a4 b5 a5 _ _ ... ]
        //         |           |
        //  inserted      stale-bound, we dont want that

        offset += (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
        bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers - offset);
      }
      prev_jacobsthal = curr_jacobsthal;
      inserted_numbers += jacobsthal_diff;
      offset = 0;
    }
  /* Insert the remaining elements in the reversed order. Here we also want to
    perform as less comparisons as possible, so we calculate the starting bound
    to insert pend number to be the pair of the first pend number. If the first
    pend number is b8, the bound is a8, if the pend number is b7, the bound is a7 etc.
    With the way I do it the index of bound is
    size_of_main - size_of_pend + index_of_current_pend. */
    for (ssize_t i = pend.size() - 1; i >= 0; i--)
    {
        typename std::vector<Iterator>::iterator curr_pend = next(pend.begin(), i);
        typename std::vector<Iterator>::iterator curr_bound =
            next(main.begin(), main.size() - pend.size() + i + is_odd);
        typename std::vector<Iterator>::iterator idx =
            std::upper_bound(main.begin(), curr_bound, *curr_pend, Compare<Iterator>);
        main.insert(idx, *curr_pend);
    }

    /* Use copy vector to store all the numbers, in order not to overwrite the
      original iterators. */
    std::vector<int> copy;
    copy.reserve(container.size());
    for (typename std::vector<Iterator>::iterator it = main.begin(); it != main.end(); it++)
    {
        for (int i = 0; i < pair_level; i++)
        {
            Iterator pair_start = *it;
            std::advance(pair_start, -pair_level + i + 1);
            copy.insert(copy.end(), *pair_start);
        }
    }

    /* Replace values in the original container. */
    Iterator container_it = container.begin();
    std::vector<int>::iterator copy_it = copy.begin();
    while (copy_it != copy.end())
    {
        *container_it = *copy_it;
        container_it++;
        copy_it++;
    }
}

#endif