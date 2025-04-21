# Integers

Integer types like ``int``and ``long``store  **whole numbers** and are used when you don't need fractional precision but want to work with larger or smaller whole values.

# Floating-point numbers

Floating-point numbers like `double` (and `float`) store **real numbers**, including fractions/decimals, and are used when you need to represent numbers with a fractional part or very large/small numbers.

- The **decimal point floats to adapt**, providing a wider range but at the cost of precision. This is why it has a **dynamic range**.
    
In the context of floating-point numbers, the term "dynamic" refers to the fact that the position of the decimal (or binary) point can change depending on the number being represented. This allows floating-point numbers to handle both very large and very small values efficiently.

## 1. Representation

Floating-point numbers represent real numbers using a scientific notation format. A number is split into two parts:

    - Mantissa: The significant digits of the number.
    - Exponent: Determines the scale of the number (where the decimal point is located).

## 2. Range
They can represent a **wide range** of values (very small to very large numbers).

## 3. Precision

Both the mantissa and exponent have a limited number of bits:

    The mantissa gets a fixed number of bits (e.g., 23 bits in single-precision floating point).
    The exponent also gets a fixed number of bits (e.g., 8 bits in single-precision floating point).

As the **magnitude of the number increases** (larger exponent), fewer bits remain available to represent the fractional part of the number. This is because the available bits in the mantissa are spread over a larger range, meaning the **precision of smaller details (like fractions) is lost**.

**_Precision Decreases with Larger Numbers_**

When dealing with **small numbers**, the floating-point representation can store small fractions accurately because the mantissa is focused on small differences around the decimal point.

# Fixed-Point Numbers

## 1. Representation
Fixed-point numbers represent numbers with a fixed number of digits before and after the decimal point (or binary point in case of binary systems). The position of the decimal point is **fixed** in advance.

***Example:***
- Fixed-Point: 12345 (integer part) + 6789 (fractional part, treated separately with a fixed precision)

## 2. Range

Has a more **limited range** than floating-point numbers because the number of bits is fixed and shared between the integer and fractional parts.

***Example:***

If you define a fixed-point number with a certain precision (e.g., 2 digits after the decimal), it can only represent numbers within a certain limited range like ``-9999.99`` to ``9999.99``. Once you hit that limit, you can't represent larger or smaller values without losing precision or range.

## 3. Precision

Fixed-point numbers can offer better precision at a given bit width compared to floating-point numbers within a smaller range.

# Fixed-Point Numbers vs Floating-Point Numbers
Fixed-point numbers are useful when you need to **control precision and ensure that operations happen consistently**, while floating-point numbers are better for handling very large ranges of values.

# Copy Constructor
The **copy constructor** is a special member function that initializes an object using another object of the same class.

`` Fixed(const Fixed &fixed); ``

This constructor takes a constant reference to another Fixed object as its parameter. The purpose of the copy constructor is to create a new Fixed object with the same state (i.e., the same values for its member variables) as the Fixed object passed to it.

 This is particularly useful for creating copies of objects when passing them to functions, returning them from functions, or initializing new objects with the state of existing objects.

## Copy Assignment Constructor

The copy assignment operator overload is used to copy the state of the fixed object into the current object. The operator= overload is a member function that takes a reference to a Fixed object as a parameter and returns a reference to a Fixed object.

```cpp
Fixed &Fixed::operator=(const Fixed &fixed)
{
    if (this != &fixed)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        _value = fixed.getRawBits();
    } 
    return *this;
}
```

# Copy Constructor vs Copy Assignment Operator

The **copy constructor** is used to initialize a new object as a copy of an existing object. It's called when an object is initialized with another object's value **at the time of declaration**.

The **copy assignment operator**, on the other hand, is used to copy the contents of one object to another existing object. It's called **when you assign one object to another after both objects have already been initialized**.


#### Example:
```cpp
Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}
```
The copy constructor uses the copy assignment operator (operator=) of the Fixed class to copy the state of the fixed object into the current object.

# this
In C++, this is a keyword that refers to the pointer to the current object instance that the method (or member function) is operating on. When you use this in a member function of a class, it points to the object for which the member function was called. **Dereferencing this yields the current object itself, not just a pointer to it.**

# Integer to Fixed-Point Number

```cpp
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _value = value << _fractionalBits;
}
```
We want to convert an integer to a fixed-point representation with 8 bits reserved for the fractional part.
This technique is often used in fixed-point arithmetic to convert an integer to a fixed-point representation, where _fractionalBits determines the number of bits used to represent the fractional part of the number.

# Integer to Fixed-Point Number
```cpp
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(value * (float)(1 << _fractionalBits));
}
```
The roundf function is used to round the result of the multiplication to the nearest integer. This is necessary because the internal representation is an integer type, and this step ensures the value is correctly rounded after scaling.

# Insertion poperator assignment 
```cpp
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
```
This code snippet enables the use of the << operator with Fixed objects, allowing them to be printed directly to output streams by first converting them to their floating-point representation via the toFloat() member function.
The compiler looks for an operator<< function that matches the types on both sides of the operator.
It finds the overloaded operator<< function we've defined, which accepts an std::ostream on the left and a Fixed object on the right.

# const in the end of a member function

The `const` at the end of the function declaration `int toInt(void) const;` in C++ indicates that this member function does not modify any member variables of the object on which it is called. This allows the function to be called on `const` instances of the class. It's a promise that the function is read-only with respect to the object state.