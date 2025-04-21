#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main() 
{
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    try {
        std::cout << *easyfind(v, 5) << std::endl;
        std::cout << *easyfind(v, 10) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Element not found in vector" << std::endl;
    }

    // Test with std::list
    std::list<int> l;
    for (int i = 0; i < 10; i++)
        l.push_back(i);
    try {
        std::cout << *easyfind(l, 5) << std::endl;
        std::cout << *easyfind(l, 10) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Element not found in list" << std::endl;
    }

    // Test with std::deque
    std::deque<int> d;
    for (int i = 0; i < 10; i++)
        d.push_back(i);
    try {
        std::cout << *easyfind(d, 5) << std::endl;
        std::cout << *easyfind(d, 10) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Element not found in deque" << std::endl;
    }
}