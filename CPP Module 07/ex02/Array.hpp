#ifndef EX02_ARRAY_HPP
#define EX02_ARRAY_HPP

#include <iostream>
#include <cstdlib> 
#include <ctime>

//Exceptions are typically defined as public members of a class. 
//This is because exceptions are meant to be thrown and caught by 
//code outside the class, and making them public ensures that they
// are accessible wherever they need to be used.

//If an exception class is private, it cannot be caught by code 
//outside the class. This would make it impossible for users of
// the class to handle the exception properly.

template <typename T>
class Array {
    private:
        T *_array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        ~Array();
        Array &operator=(const Array &other);
        T &operator[](unsigned int i);
        unsigned int size() const;

        class OutOfLimitsException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

#include "Array.tpp"

#endif //EX02_ARRAY_HPP