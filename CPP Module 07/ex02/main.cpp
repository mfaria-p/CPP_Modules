#include "Array.hpp"

class ComplexType {
public:
    ComplexType() : _value(0) {}
    ComplexType(int value) : _value(value) {}
    int getValue() const { return _value; }
    void setValue(int value) { _value = value; }
private:
    int _value;
};

std::ostream &operator<<(std::ostream &os, const ComplexType &obj) {
    os << obj.getValue();
    return os;
}

int main() {
    Array<int> intArray(5);
    Array<char> charArray(5);
    Array<std::string> stringArray(5);
    Array<ComplexType> complexArray(5);

    std::cout << std::endl;
    std::cout << "intArray:" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i + 1;
        std::cout << intArray[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "charArray:" << std::endl;
    for (unsigned int i = 0; i < charArray.size(); i++) {
        charArray[i] = 'a' + i;
        std::cout << charArray[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "stringArray:" << std::endl;
    stringArray[0] = "apple";
    stringArray[1] = "banana";
    stringArray[2] = "cherry";
    stringArray[3] = "pear";
    stringArray[4] = "berry";
    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << stringArray[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "complexArray:" << std::endl;
    for (unsigned int i = 0; i < complexArray.size(); i++) {
        complexArray[i] = ComplexType(i * 10);
        std::cout << complexArray[i] << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Trying to access an element out of limits:" << std::endl;
        std::cout << stringArray[5] << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Trying to construct an array with negative elements:" << std::endl;
    Array<int> negativeArray(-2);
    std::cout << std::endl;
    try {
        std::cout << "Trying to access an element from an array that failed:" << std::endl;
        std::cout << negativeArray[0] << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try
    {
        negativeArray[0] = 1;
    }
    catch(std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    return 0;
}