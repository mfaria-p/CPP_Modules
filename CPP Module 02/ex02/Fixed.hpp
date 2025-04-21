#ifndef EX02_FIXED_HP
# define EX02_FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int					_value;
    static const int	_fractionalBits = 8;
public:
    Fixed(); //default constructor
    Fixed(const int value); //receive an integer and store it as the fixed-point value
    Fixed(const float value); //receive a float and store it as the fixed-point value
    Fixed(const Fixed &fixed); //copy constructor
    ~Fixed(); //destructor

    int getRawBits(void) const; //returns the raw value of the fixed-point number
    void setRawBits(int const raw); //sets the raw value of the fixed-point number

    Fixed &operator=(const Fixed &fixed); //copy assignment operator overload
    Fixed operator++(); //pre-increment operator overload
    Fixed operator++(int); //post-increment operator overload
    Fixed operator--(); //pre-decrement operator overload
    Fixed operator--(int); //post-decrement operator overload
    Fixed operator+(const Fixed &fixed) const; //addition operator overload
    Fixed operator-(const Fixed &fixed) const; //subtraction operator overload
    Fixed operator*(const Fixed &fixed) const; //multiplication operator overload
    Fixed operator/(const Fixed &fixed) const; //division operator overload
    bool operator>(const Fixed &fixed) const; //greater than operator overload
    bool operator<(const Fixed &fixed) const; //less than operator overload
    bool operator>=(const Fixed &fixed) const; //greater than or equal to operator overload
    bool operator<=(const Fixed &fixed) const; //less than or equal to operator overload
    bool operator==(const Fixed &fixed) const; //equal to operator overload
    bool operator!=(const Fixed &fixed) const; //not equal to operator overload

    static Fixed& min(Fixed &ref1, Fixed &ref2); //returns the smallest of two fixed-point numbers
    static const Fixed& min(const Fixed &ref1, const Fixed &ref2); //returns the smallest of two fixed-point numbers
    static Fixed& max(Fixed &ref1, Fixed &ref2); //returns the largest of two fixed-point numbers
    static const Fixed& max(const Fixed &ref1, const Fixed &ref2); //returns the largest of two fixed-point numbers

    float toFloat(void) const; //converts the fixed-point value to a floating-point value
    int toInt(void) const; //converts the fixed-point value to an integer value
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif