#ifndef EX00_CLAPTRAP_HPP
#define EX00_CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        unsigned int _attackDamage;
    public:
        ClapTrap(); //default constructor
        ClapTrap(std::string name); //parameterized constructor
        ClapTrap(const ClapTrap &obj); //copy constructor
        ~ClapTrap(); //destructor
        ClapTrap &operator=(const ClapTrap &obj); //assignment operator
        void attack(std::string const &target);
        void attackTarget(ClapTrap &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void setAttackDamage( unsigned int amount );
        void status(void) const;
};


#endif