#include "Span.hpp"

#include <iostream>
#include <vector>
#include "Span.hpp"  // Assuming Span class is properly implemented

int main() {
    std::cout << "TEST WITH SPAN OF SIZE 5" << std::endl;
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try {
        sp.addNumber(11);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    std::cout << std::endl;

    std::cout << "TEST WITH SPAN OF SIZE 10000" << std::endl;
    Span sp2 = Span(10000);
    std::vector<int> v;
    for (int i = 0; i < 10000; i++)
        v.push_back(i);
    try {
        sp2.addNumbers(v.begin(), v.end());
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

    std::cout << std::endl;

    std::cout << "TEST WITH SPAN OF SIZE 1 (should throw exception)" << std::endl;
    Span sp3 = Span(1);
    sp3.addNumber(42);
    try {
        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "TEST WITH SPAN OF SIZE 0 (should throw exception)" << std::endl;
    Span sp4 = Span(0);
    try {
        sp4.addNumber(1);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "TEST WITH SPAN OF SIZE 5 AND ADDING A RANGE OF NUMBERS" << std::endl;
    Span sp5 = Span(5);
    std::vector<int> v2;
    v2.push_back(1);
    v2.push_back(654);
    v2.push_back(54334);
    v2.push_back(344);
    v2.push_back(543222);
    try {
        sp5.addNumbers(v2.begin(), v2.end());
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp5.longestSpan() << std::endl;

    std::cout << std::endl;

    std::cout << "TEST WITH SPAN OF SIZE 5 AND ADDING A RANGE OF NUMBERS THAT EXCEEDS THE CAPACITY" << std::endl;
    Span sp6 = Span(5);
    std::vector<int> v3;
    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(3);
    v3.push_back(4);
    v3.push_back(5);
    v3.push_back(6);
    try {
        sp6.addNumbers(v3.begin(), v3.end());
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
