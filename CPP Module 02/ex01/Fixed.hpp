#ifndef EX01_FIXED_HP
# define EX01_FIXED_HPP

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
    Fixed &operator=(const Fixed &fixed); //copy assignment operator overload
    int getRawBits(void) const; //returns the raw value of the fixed-point number
    void setRawBits(int const raw); //sets the raw value of the fixed-point number
    float toFloat(void) const; //converts the fixed-point value to a floating-point value
    int toInt(void) const; //converts the fixed-point value to an integer value
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif