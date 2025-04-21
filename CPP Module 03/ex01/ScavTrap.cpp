#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->_name = "Anonymous";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << _name << " is born!" << std::endl;
}

ScavTrap::ScavTrap( std::string _name ) : ClapTrap( _name )
{
    this->_name = _name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << _name << " is born!" << std::endl;
}
//In C++, when you define a copy constructor for a derived class, 
//you need to explicitly call the copy constructor of the base class in the member initializer list.
ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj) {
    *this = obj;
    std::cout << "ScavTrap " << _name << " is born!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " died!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj) {
    if (this != &obj)
    {
        _name = obj._name;
        _hitPoints = obj._hitPoints;
        _energyPoints = obj._energyPoints;
        _attackDamage = obj._attackDamage;
    }
    return *this;
}

void ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode!" << std::endl;
}

void ScavTrap::attack( const std::string& target )
{
    if (_energyPoints >= 0)
        _energyPoints--;
    else
    {
        std::cout << "ScavTrap " << _name << " doesn't have enough energy to attack!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}
