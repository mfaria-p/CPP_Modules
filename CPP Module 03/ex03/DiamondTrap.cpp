#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _name("Anonymous")
{
    ClapTrap::_name = _name + "_clap_name";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
    std::cout << "DiamondTrap " << this->_name << " is born!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string _name)
    : ClapTrap(_name + "_clap_name"), ScavTrap(_name + "_clap_name"), FragTrap(_name + "_clap_name"), _name(_name)
{
    ClapTrap::_name = _name + "_clap_name";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
    std::cout << "DiamondTrap " << this->_name << " is born!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj), _name(obj._name)
{
    *this = obj;
    std::cout << "DiamondTrap " << this->_name << " is born!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj) {
    if (this != &obj)
    {
        ScavTrap::operator=(obj);
        FragTrap::operator=(obj);
        _name = obj._name;
        _hitPoints = obj._hitPoints;
        _energyPoints = obj._energyPoints;
        _attackDamage = obj._attackDamage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_name << " died!" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
    std::cout << "My DiamondTrap name is " << this->_name << std::endl;
}