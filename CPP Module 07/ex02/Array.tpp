#ifndef EX02_ARRAY_TPP
#define EX02_ARRAY_TPP

#include "Array.hpp"

// The default constructor initializes the array to an empty array of zero elements.
//It provides a consistent state for the Array object, where array always points to 
//a valid memory location, even if it doesn't contain any elements.
template <typename T>
Array<T>::Array()
{
    _size = 0;
    try
    {
        _array = new T[0];
        std::cout << "Array default constructor has been called" << std::endl;
    }
    catch(std::bad_alloc&)
    {
        std::cerr << "Allocation of the array failed" << std::endl;
        _array = NULL;
    }
}

// The constructor with a size parameter initializes the array to a new array of size n.
template <typename T>
Array<T>::Array(unsigned int n)
{
    if (n > 1000000) 
    { 
        std::cerr << "Size of array can't be neither too large or negative" << std::endl;
        _array = NULL;
        _size = 0;
        return;
    }
    try
    {
        _array = new T[n];
        _size = n;
        std::cout << "Array parameterized constructor has been called" << std::endl;
    }
    catch(std::bad_alloc&)
    {
        std::cerr << "Allocation of the array failed" << std::endl;
        _array = NULL;
        _size = 0;
    }
}

// The copy constructor initializes the array to a new array of the same size as the other array and copies the elements from the other array to the new array.
template <typename T>
Array<T>::Array(const Array &other)
{
    try
    {
        _size = other._size;
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
        {
            _array[i] = other._array[i];
        }
        std::cout << "Array copy constructor has been called" << std::endl;
    }
    catch(std::bad_alloc&) 
    {
        std::cerr << "Allocation of the array failed" << std::endl;
        _array = NULL;
        _size = 0;
    }
}

// The destructor deletes the array.
template <typename T>
Array<T>::~Array()
{
    if (_array)
        delete[] _array;
    std::cout << "Array destructor has been called" << std::endl;
}

// The assignment operator copies the elements from the other array to the current array.
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this == &other)
        return *this;
    if (_array)
        delete[] _array;
    try
    {
        _array = new T[_size];
        _size = other._size;
        for (unsigned int i = 0; i < _size; i++)
        {
            _array[i] = other._array[i];
        }
    }
    catch(std::bad_alloc&) 
    {
        std::cerr << "Allocation of the array failed" << std::endl;
        _array = NULL;
        _size = 0;
    }
    return *this;
}

// The operator[] returns a reference to the element at index i.
template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw OutOfLimitsException();
    return _array[i];
}

// The size() function returns the size of the array.
template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

// The what() function returns a string that describes the exception.
template <typename T>
const char *Array<T>::OutOfLimitsException::what() const throw()
{
    return "Error: index out of limits";
}

#endif //EX02_ARRAY_TPP