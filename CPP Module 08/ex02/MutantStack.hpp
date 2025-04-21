#ifndef EX02_MUTANTSTACK_HPP
#define EX02_MUTANTSTACK_HPP

#include <iostream>
#include <stack>

//std::stack is implemented as a container adapter, meaning it uses an internal container (like std::deque by default) to store elements
//This internal container is protected (not directly accessible), but since std::stack is based on a standard container, it provides 
//access to its underlying container through the protected member c.
//c.begin() and c.end() allow us to access the iterators of the internal container.
//Why Use Container Adapters? They provide a simplified interface for specific use cases and they restrict access to only necessary operations.
//In this case, std::stack provides a LIFO (Last In, First Out) data structure, and the underlying container is protected to prevent misuse.

template<typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() : std::stack<T>() {}

    MutantStack(const MutantStack &src) : std::stack<T>(src) {}

    ~MutantStack() {}

    MutantStack &operator=(const MutantStack &other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() {
        return std::stack<T>::c.begin();
    }

    iterator end() {
        return std::stack<T>::c.end();
    }
};

#endif //EX02_MUTANTSTACK_HPP