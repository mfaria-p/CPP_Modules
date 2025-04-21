#ifndef EX00_ANIMAL_HPP
# define EX00_ANIMAL_HPP

# include <iostream>

//A pure virtual function in C++ makes it impossible to instantiate a class 
//because the class is considered incomplete. When a class has at least one 
//pure virtual function, it is treated as an abstract class, which means that
// it is designed to be a base class, intended to be inherited by other classes, 
//rather than instantiated directly.

class Animal
{
protected:
    std::string type;

public:
    Animal();
    Animal( std::string type );
    virtual ~Animal();
    Animal( const Animal& other );
    Animal& operator=( const Animal& other );
    
    std::string getType() const;
    virtual void makeSound() const = 0;
};

#endif