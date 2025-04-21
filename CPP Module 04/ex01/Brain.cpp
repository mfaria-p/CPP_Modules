#include "includes/Brain.hpp"

Brain::Brain() 
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain( const Brain& other )
{
    *this = other;
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=( const Brain& other )
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            this->_ideas[i] = other._ideas[i];
        }
    }
    std::cout << "Brain assignment operator called" << std::endl;
    return *this;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return _ideas[index];
    }
    return "";
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        _ideas[index] = idea;
    }
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}