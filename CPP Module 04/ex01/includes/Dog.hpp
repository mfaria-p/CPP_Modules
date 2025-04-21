#ifndef EX00_DOG_HPP
# define EX00_DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain* _brain;

public:
    Dog();
    ~Dog();
    Dog( const Dog& other );
    Dog& operator=( const Dog& other );

    void makeSound() const;
    Brain* getBrain() const;
};

#endif