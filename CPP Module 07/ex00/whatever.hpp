#ifndef EX00_WHATEVER_HPP
#define EX00_WHATEVER_HPP

#include <iostream>

//Templates in C++ are a feature that allows functions and
// classes to operate with generic types. This means you can 
//write a function or a class to work with any data type 
//without having to rewrite the code for each type. Templates
// are a powerful tool for creating reusable and type-safe code.

//In C++ templates, the keyword typename is used to specify 
//that T is a type parameter. This means that T can be any 
//data type (e.g., int, double, char, etc.) when the template is instantiated.

template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

template <typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

#endif //EX00_WHATEVER_HPP