#include "includes/Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
} // Default constructor

Animal::Animal( std::string type ) : type(type) {
    std::cout << "Animal constructor called" << std::endl;
} // Parameterized constructor

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
} // Destructor

Animal::Animal( const Animal& other ) {
    *this = other;
    std::cout << "Animal copy constructor called" << std::endl;
} // Copy constructor

Animal& Animal::operator=( const Animal& other ) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "Animal assignment operator called" << std::endl;
    return *this;
} // Assignment operator

std::string Animal::getType() const {
    return this->type;
} // Member function

void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
} // Member function