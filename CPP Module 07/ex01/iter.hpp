#ifndef EX01_ITER_HPP
#define EX01_ITER_HPP

#include <iostream>

//The function iter takes an array of type T, an integer that
//represents the size of the array, and a function pointer that
//takes a reference to an element of the array as an argument.
//The function iter applies the function to each element of the array.

template <typename T>
void iter(T *array, int size, void (*func)(T &)) 
{
    if (!array || size <= 0 || !func)
        return;
    for (int i = 0; i < size; i++)
        func(array[i]);
}

template <typename T>
void iter(const T *array, int size, void (*func)(const T &)) 
{
    if (!array || size <= 0 || !func)
        return;
    for (int i = 0; i < size; i++)
        func(array[i]);
}

#endif //EX01_ITER_HPP