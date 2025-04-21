#include "Span.hpp"

Span::Span() : _maxsize(0) {}

Span::Span(unsigned int N) : _maxsize(N) {}

Span::Span(const Span &src): _maxsize(src._maxsize) {
    _v = src._v;
}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxsize = other._maxsize;
        _v = other._v;
    }
    return *this;
}

void Span::addNumber(int n) {
    if (_v.size() >= _maxsize)
        throw Span::SpanFullException();
    _v.push_back(n);
}

int Span::shortestSpan() {
    if (_v.size() <= 1)
        throw Span::SpanException();
    std::vector<int> v = _v;
    std::sort(v.begin(), v.end());
    int min = v[1] - v[0];
    for (size_t i = 2; i < v.size(); i++) {
        if (v[i] - v[i - 1] < min)
            min = v[i] - v[i - 1];
    }
    return min;
}

int Span::longestSpan() {
    if (_v.size() <= 1)
        throw Span::SpanException();
    std::vector<int> v = _v;
    std::sort(v.begin(), v.end());
    return v[v.size() - 1] - v[0];
}

//Before modifying _v, the function checks whether inserting all elements would exceed 
//_maxsize.
//If _v.size() + number of new elements > _maxsize, an exception is thrown
//If the exception is thrown, _v remains unchanged.

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (_v.size() + std::distance(begin, end) > _maxsize)
        throw Span::SpanFullException();
    _v.insert(_v.end(), begin, end);
}

Span::SpanException::SpanException() {}

Span::SpanException::SpanException(const Span::SpanException &src) {
    *this = src;
}

Span::SpanException::~SpanException() throw() {}

Span::SpanException &Span::SpanException::operator=(const Span::SpanException &other) {
    (void)other;
    return *this;
}

const char *Span::SpanException::what() const throw() {
    return "Error: No span to find. Check that there are at least 2 numbers in the container.";
}

Span::SpanFullException::SpanFullException() {}

Span::SpanFullException::SpanFullException(const Span::SpanFullException &src) {
    *this = src;
}  

Span::SpanFullException::~SpanFullException() throw() {}

Span::SpanFullException &Span::SpanFullException::operator=(const Span::SpanFullException &other) {
    (void)other;
    return *this;
}

const char *Span::SpanFullException::what() const throw() {
    return "Error: Container is full. Cannot add more numbers.";
}
