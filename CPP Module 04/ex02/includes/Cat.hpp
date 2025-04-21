#ifndef EX00_CAT_HPP
# define EX00_CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain* _brain;

public:
    Cat();
    ~Cat();
    Cat( const Cat& other );
    Cat& operator=( const Cat& other );

    void makeSound() const;
    Brain* getBrain() const;
};

#endif