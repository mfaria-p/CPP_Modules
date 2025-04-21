#include "includes/Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog constructor called" << std::endl;
} // Default constructor

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
} // Destructor

Dog::Dog( const Dog& other ): Animal(other) {
    *this = other;
    std::cout << "Dog copy constructor called" << std::endl;
} // Copy constructor

Dog& Dog::operator=( const Dog& other ) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
} // Assignment operator

void Dog::makeSound() const {
    std::cout << "Woof Woof" << std::endl;
} // Member function