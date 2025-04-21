#ifndef EX00_ANIMAL_HPP
# define EX00_ANIMAL_HPP

# include <iostream>
//The destructor of the Animal class needs to be virtual to ensure 
//that the destructors of derived classes are called correctly when
// an object is deleted through a pointer to the base class. Without 
//a virtual destructor, only the base class destructor would be called,
// potentially leading to resource leaks or undefined behavior if the 
//derived class has allocated resources that need to be released.

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
    virtual void makeSound() const;
};

#endif