#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//When you use the assignment operator, like a = b; where both a and b 
//are objects of type Fixed, a.operator=(b); is implicitly called.
Fixed &Fixed::operator=(const Fixed &fixed)
{
    if (this != &fixed)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        _value = fixed.getRawBits();
    } 
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}