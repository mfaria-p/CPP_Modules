#include "whatever.hpp"

class ComplexType {
public:
    ComplexType() : _value(0) {}
    ComplexType(int value) : _value(value) {}
    int getValue() const { return _value; }
    void setValue(int value) { _value = value; }
    bool operator<(const ComplexType &other) const { return _value < other._value; }
    bool operator>(const ComplexType &other) const { return _value > other._value; }
private:
    int _value;
};

std::ostream &operator<<(std::ostream &os, const ComplexType &obj) 
{
    os << obj.getValue();
    return os;
}

// :: is the scope resolution operator in C++. It is used to
// specify the scope of a function or a variable. In this case,
// it is used to specify that the function swap, min, and max
// are defined in the global scope.

int main() {
    int a = 2;
    int b = 3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap(a, b):" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    std::cout << std::endl;

    double c = 2.5;
    double d = 3.5;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap(c, d):" << std::endl;
    std::cout << "c = " << c << ", d = " << d << std::endl;

    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    std::cout << std::endl;

    std::string e = "apple";
    std::string f = "banana";
    std::cout << "e = " << e << ", f = " << f << std::endl;
    ::swap(e, f);
    std::cout << "After swap(e, f):" << std::endl;
    std::cout << "e = " << e << ", f = " << f << std::endl;

    std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << ::max(e, f) << std::endl;
    std::cout << std::endl;

    std::string g = "chaine1";
    std::string h = "chaine2";
    std::cout << "g = " << g << ", h = " << h << std::endl;
    ::swap(g, h);
    std::cout << "After swap(g, h):" << std::endl;
    std::cout << "g = " << g << ", h = " << h << std::endl;
    std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
    std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;
    std::cout << std::endl;

    ComplexType x(10);
    ComplexType y(20);
    std::cout << "x = " << x << ", y = " << y << std::endl;
    ::swap(x, y);
    std::cout << "After swap(x, y):" << std::endl;
    std::cout << "x = " << x << ", y = " << y << std::endl;

    std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

    return 0;
}

//Comparing strings lexicographically means comparing them 
//based on the alphabetical order of their characters, similar 
//to how words are ordered in a dictionary.
//Each character is compared based on its ASCII value