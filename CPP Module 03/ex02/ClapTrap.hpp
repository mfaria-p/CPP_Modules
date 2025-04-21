#ifndef EX00_CLAPTRAP_HPP
#define EX00_CLAPTRAP_HPP

#include <iostream>

//To ensure that the attack method from the derived class ScavTrap is called, 
//you need to ensure that the attack method in the base class ClapTrap should be declared as 
//virtual in the base class. This allows the derived class method to override the base class method properly.
class ClapTrap {
    protected:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        unsigned int _attackDamage;
    public:
        ClapTrap(); //default constructor
        ClapTrap(std::string name); //parameterized constructor
        ClapTrap(const ClapTrap &obj); //copy constructor
        virtual ~ClapTrap(); //destructor
        ClapTrap &operator=(const ClapTrap &obj); //assignment operator
        virtual void attack(std::string const &target);
        void attackTarget(ClapTrap &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void setAttackDamage( unsigned int amount );
        void status(void) const;
};


#endif