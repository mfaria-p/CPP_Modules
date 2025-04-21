#ifndef EX00_EASYFIND_HPP
#define EX00_EASYFIND_HPP

#include <algorithm>
#include <iostream>

//A container is a data structure that stores a collection of elements. 
//The C++ Standard Library provides several container types, such as std::vector,
// std::list, std::map, and std::set.
//Each container type has its own set of member functions and iterators.

//In C++, an iterator is an object that enables a programmer to traverse a container, 
//particularly lists, vectors, and other data structures.

//The std::find() algorithm is used to search for an element in a container.
//It returns an iterator to the first element in the range [first, last) that matches the given value.
//If no such element is found, it returns the last iterator.
//The std::find() algorithm is defined in the <algorithm> header file.

template<typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();
    return it;
}

#endif //EX00_EASYFIND_HPP