#include "includes/Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog constructor called" << std::endl;
    this->_brain = new Brain();
} // Default constructor

Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog destructor called" << std::endl;
} // Destructor

Dog::Dog( const Dog& other ): Animal(other)
{
    *this = other;
    std::cout << "Dog copy constructor called" << std::endl;
} // Copy constructor

Dog& Dog::operator=( const Dog& other ) {
    if (this != &other) {
        this->type = other.type;
        this->_brain = new Brain(*other._brain);
    }
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
} // Assignment operator

void Dog::makeSound() const {
    std::cout << "Woof Woof" << std::endl;
} // Member function

Brain* Dog::getBrain() const {
    return _brain;
}