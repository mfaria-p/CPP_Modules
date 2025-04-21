#include "includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
} // Default constructor

Cat::~Cat() 
{
    std::cout << "Cat destructor called" << std::endl;
} // Destructor

Cat::Cat( const Cat& other ): Animal(other) 
{
    *this = other;
    std::cout << "Cat copy constructor called" << std::endl;
} // Copy constructor

Cat& Cat::operator=( const Cat& other ) 
{
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
} // Assignment operator

void Cat::makeSound() const 
{
    std::cout << "Meow Meow" << std::endl;
} // Member function