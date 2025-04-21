#include "includes/WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &cat): WrongAnimal(cat)
{
    *this = cat;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &cat)
{
    if (this != &cat)
    {
        this->_wrong_type = cat._wrong_type;
    }
    std::cout << "WrongCat assignment operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void)
{
    std::cout << "MiAo MiAo" << std::endl;
}