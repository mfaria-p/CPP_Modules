#include "PmergeMe.hpp"
#include <cmath>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include <set>
#include <cerrno>

static std::string ValidateNbr(std::string str)
{
    if (str[0] == '-')
        return "Negative numbers are not allowed";
    long nbr = strtol(str.c_str(), NULL, 10);
    if (nbr == 0 && str != "0")
        return "Non-number arguments not allowed";
    if (nbr > INT_MAX || errno == ERANGE) //The errno variable is set to ERANGE if the number is too large to fit in an int.
        return "Too big arguments are not allowed";
    return "";
}

static std::string ValidateArg(int ac, char** av)
{
    if (ac == 1)
        return "No arguments were provided";
    for (int i = 1; i < ac; i++)
    {
        std::string status = ValidateNbr(av[i]);
        if (status != "")
            return status;
    }
    return "";
}

static std::set<int> SaveOriginal(int ac, char** av)
{
    std::set<int> original_values;
    for (int i = 1; i < ac; i++)
    {
        original_values.insert(std::atoi(av[i]));
    }
    return original_values;
}

static std::vector<int> AvtoVec(int ac, char** av)
{
    std::vector<int> vec;
    for (int i = 1; i < ac; i++)
    {
        vec.push_back(std::atoi(av[i]));
    }
    return vec;
}

static std::deque<int> AvtoDeque(int ac, char** av)
{
    std::deque<int> deque;
    for (int i = 1; i < ac; i++)
    {
        deque.push_back(std::atoi(av[i]));
    }
    return deque;
}

template <typename T> static bool IsSorted(const T& container)
{
    if (container.size() == 0 || container.size() == 1)
        return true;
    typename T::const_iterator end = container.end();
    std::advance(end, -1);
    for (typename T::const_iterator it = container.begin(); it != end; it++)
    {
        typename T::const_iterator next = it;
        std::advance(next, 1);
        if (*it > *next)
            return false;
    }
    return true;
}

static bool RetainedOriginal(std::set<int>& original_values, std::vector<int>& vec)
{
	for (int i = 0; i < (int)vec.size(); i++)
	{
		if (original_values.find(vec[i]) == original_values.end())
        {
            std::cerr << "Error: " << vec[i] << " is not in the original set.\n";
			return false;
        }
	}
	return true;
}

static std::string AvtoStr(int ac, char** av)
{
    std::string res("");
    res.reserve(ac + 1);
    res += av[1];
    for (int i = 2; av[i]; i++)
    {
        res += " ";
        res += av[i];
    }
    return res;
}

static std::string VectoStr(std::vector<int>& vec)
{
    std::stringstream ss;
    ss << vec[0];
    for (size_t i = 1; i < vec.size(); i++)
    {
        ss << " " << vec[i];
    }
    return ss.str();
}

int main(int ac, char** av)
{
    PmergeMe pm;
	
    std::string error = ValidateArg(ac, av);
    if (error != "")
    {
        std::cerr << "Error: " << error << "\n";
        return EXIT_FAILURE;
    }

    std::set<int> original_values = SaveOriginal(ac, av);

    //Clock ticks are the smallest unit of time measured by the CPU's internal clock
    //CLOCKS_PER_SEC is a macro representing the number of clock ticks per second.

    //Vector
    clock_t start_vec = clock();
    std::vector<int> vec = AvtoVec(ac, av);
    pm.SortVec(vec);
    clock_t end_vec = clock();
    double time_taken_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

    //Deque
    clock_t start_deque = clock();
    std::deque<int> deque = AvtoDeque(ac, av);
    pm.SortDeque(deque);
    clock_t end_deque = clock();
    double time_taken_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC;

    if (!IsSorted(vec) || (int)vec.size() != (ac - 1) || !RetainedOriginal(original_values, vec))
	{
        std::cout << "Vector was not sorted properly.\n";
		return 1;
	}

    if (!IsSorted(deque) || (int)deque.size() != (ac - 1))
    {
        std::cout << "Deque was not sorted properly.\n";
        return 1;
    }

    std::cout << "Before: " << AvtoStr(ac, av) << "\n";
    std::cout << "After:  " << VectoStr(vec) << "\n";
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector: " << std::fixed << std::setprecision(6) << time_taken_vec << "s\n";
    std::cout << "Time to process a range of " << deque.size()
              << " elements with std::deque: " << std::fixed << std::setprecision(6) << time_taken_deque << "s\n";
}
