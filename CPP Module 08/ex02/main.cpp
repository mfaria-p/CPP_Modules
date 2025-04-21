#include <list>
#include "MutantStack.hpp"

void testMutantStack() {
    std::cout << "Testing MutantStack" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(42);
    mstack.push(989);
    mstack.push(0);

    std::cout << "Iterating over MutantStack:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "Copying MutantStack to std::stack..." << std::endl;
    std::stack<int> s(mstack);
    while (!s.empty()) {
        std::cout << "Popping from std::stack: " << s.top() << std::endl;
        s.pop();
    }

    std::cout << "Clearing MutantStack..." << std::endl;
    while (!mstack.empty()) {
        std::cout << "Popping: " << mstack.top() << std::endl;
        mstack.pop();
    }
    std::cout << "Final size: " << mstack.size() << std::endl;
}

void testList() {
    std::cout << "\nTesting std::list" << std::endl;
    std::list<int> mlist;

    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << "Top: " << mlist.back() << std::endl;

    mlist.pop_back();
    std::cout << "Size: " << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(42);
    mlist.push_back(989);
    mlist.push_back(0);

    std::cout << "Iterating over std::list:" << std::endl;
    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "Clearing std::list..." << std::endl;
    while (!mlist.empty()) {
        std::cout << "Popping: " << mlist.back() << std::endl;
        mlist.pop_back();
    }
    std::cout << "Final size: " << mlist.size() << std::endl;
}

int main() {
    testMutantStack();
    testList();
    return 0;
}

