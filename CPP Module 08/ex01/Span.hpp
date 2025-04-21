#ifndef EX01_SPAN_HPP
#define EX01_SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span {
private:
    unsigned int _maxsize;
    std::vector<int> _v;
public:
    Span(); // Default constructor
    Span(unsigned int N); // Parametric constructor
    Span(const Span &src); // Copy constructor
    ~Span(); // Destructor
    Span &operator=(const Span &other); // Assignation operator

    void addNumber(int n);
    int shortestSpan();
    int longestSpan();
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    class SpanException : public std::exception {
    public:
        SpanException();
        SpanException(const SpanException &src);
        virtual ~SpanException() throw();
        SpanException &operator=(const SpanException &other);
        virtual const char *what() const throw();
    };

    class SpanFullException : public std::exception {
    public:
        SpanFullException();
        SpanFullException(const SpanFullException &src);
        virtual ~SpanFullException() throw();
        SpanFullException &operator=(const SpanFullException &other);
        virtual const char *what() const throw();
    };

};

#endif //EX01_SPAN_HPP
