#ifndef EX00_ANIMAL_HPP
# define EX00_ANIMAL_HPP

# include <iostream>

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