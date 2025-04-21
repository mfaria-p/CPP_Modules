#include "includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _wrong_type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ): _wrong_type(type) 
{
    std::cout << "WrongAnimal constructor called" << std::endl;
} 

WrongAnimal::WrongAnimal(WrongAnimal const &type)
{
    *this = type;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &WrongAnimal)
{
    if (this != &WrongAnimal)
    {
        this->_wrong_type = WrongAnimal._wrong_type;
    }
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound(void)
{
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->_wrong_type;
}