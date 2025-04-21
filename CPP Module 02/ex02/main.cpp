#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}

//Not all decimal fractions can be represented exactly as binary fractions, leading to approximations.
//If the Fixed class converts floating-point numbers to a fixed-point representation, it involves 
//scaling and possibly rounding the floating-point number to fit within the fixed number of bits 
//allocated for fractional parts. This process can introduce additional small discrepancies due to the precision limit of the fixed-point representation.
//the smallest step is 1 / (2^_fractionalBits) = 1 / 256 = 0.00390625 (in float represetnation)
/*int main() {
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.75f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    std::cout << std::endl;

    // Arithmetic operations
    std::cout << "c + d = " << c + d << std::endl;
    std::cout << "c - d = " << c - d << std::endl;
    std::cout << "c * d = " << c * d << std::endl;
    std::cout << "c / d = " << c / d << std::endl;
    std::cout << std::endl;

    // Increment and decrement operators
    Fixed e;
    std::cout << "e is " << e << std::endl;
    std::cout << "++e is " << ++e << std::endl;
    std::cout << "e is " << e << std::endl;
    std::cout << "e++ is " << e++ << std::endl;
    std::cout << "e is " << e << std::endl;
    std::cout << std::endl;

     // Comparison operators
    std::cout << "(c > d) is " << (c > d) << std::endl;
    std::cout << "(c < d) is " << (c < d) << std::endl;
    std::cout << "(c >= d) is " << (c >= d) << std::endl;
    std::cout << "(c <= d) is " << (c <= d) << std::endl;
    std::cout << "(c == d) is " << (c == d) << std::endl;
    std::cout << "(c != d) is " << (c != d) << std::endl;
    std::cout << std::endl;

    // Max and Min
    std::cout << "Max of c and d is " << Fixed::max(c, d) << std::endl;
    std::cout << "Min of c and d is " << Fixed::min(c, d) << std::endl;
    std::cout << std::endl;

    return 0;
}*/
