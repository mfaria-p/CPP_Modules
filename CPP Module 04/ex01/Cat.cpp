#include "includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
    this->_brain = new Brain();
} // Default constructor

Cat::~Cat() 
{
    delete this->_brain;
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
        this->_brain = new Brain(*other._brain);
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
} // Assignment operator

void Cat::makeSound() const 
{
    std::cout << "Meow Meow" << std::endl;
} // Member function

Brain* Cat::getBrain() const {
    return _brain;
}