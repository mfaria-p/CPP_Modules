#include "PmergeMe.hpp"
#include <cmath>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& pm) { (void)pm; }
PmergeMe& PmergeMe::operator=(const PmergeMe& pm)
{
    (void)pm;
    return *this;
}
PmergeMe::~PmergeMe() {}

//The Jacobsthal numbers define the indices for selecting pend elements to insert into main, 
//and the upper-bound positions in main to compare against for insertion.
int _jacobsthal_nbr(int n) 
{ 
    return round((pow(2, n + 1) + pow(-1, n)) / 3); 
}
//The expression for the Jacobsthal numbers is 2^(n+1) + (-1)^n / 3.

void PmergeMe::SortVec(std::vector<int>& vec) 
{ 
    MergeInsertSort<std::vector<int> >(vec, 1); 
}

void PmergeMe::SortDeque(std::deque<int>& deque)
{
    MergeInsertSort<std::deque<int> >(deque, 1);
}