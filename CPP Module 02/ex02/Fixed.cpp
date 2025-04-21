#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(value * (float)(1 << _fractionalBits));
}
//5.25 in binary is 101.01.
//The integer part is 101, which is 5 in decimal.
//The fractional part is 01, which is 0.25 in decimal.
//We want 8 fractional bits, so we shift the whole number 5.25 left by 8 bits (we do this by multiplying by 2^8 = 256).
//This operation moves the point 8 positions to the right (moves the bits 8 positions to the left of the point), turning the 
//fractional part into an integer (in terms of representation).
//The final binary representation is 0000010101000000 in binary, which is 1344 in decimal.

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

//now i am moving the bits to the right (moving the point to the left) 
//to get the float number (in terms of representation), aka with the fractional part
float Fixed::toFloat(void) const
{
    return (float)_value / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _value >> _fractionalBits;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    if (this != &fixed)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        _value = fixed.getRawBits();
    } 
    return *this;
}

Fixed Fixed::operator++()
{
    _value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
   Fixed tmp(*this);
   _value++;
    return tmp; 
}

Fixed Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    _value--;
    return tmp;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    return Fixed(this->toFloat() / fixed.toFloat());
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return this->toFloat() > fixed.toFloat();
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return this->toFloat() < fixed.toFloat();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return this->toFloat() >= fixed.toFloat();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return this->toFloat() <= fixed.toFloat();
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return this->toFloat() == fixed.toFloat();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return this->toFloat() != fixed.toFloat();
}

Fixed &Fixed::min(Fixed &ref1, Fixed &ref2)
{
    return ref1 < ref2 ? ref1 : ref2;
}

const Fixed &Fixed::min(const Fixed &ref1, const Fixed &ref2)
{
    return ref1 < ref2 ? ref1 : ref2;
}

Fixed &Fixed::max(Fixed &ref1, Fixed &ref2)
{
    return ref1 > ref2 ? ref1 : ref2;
}

const Fixed &Fixed::max(const Fixed &ref1, const Fixed &ref2)
{
    return ref1 > ref2 ? ref1 : ref2;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}