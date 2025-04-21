#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    _name = "Anonymous";
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) {
    *this = obj;
    std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " died!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj) {
    if (this != &obj)
    {
        _name = obj._name;
        _hitPoints = obj._hitPoints;
        _energyPoints = obj._energyPoints;
        _attackDamage = obj._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string &target) {
    if (_energyPoints>=0)
            _energyPoints--;
    else
    {
        std::cout << "ClapTrap " << _name << " doesn't have enough energy to attack!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::attackTarget(ClapTrap &target) {
    if (_hitPoints == 0)
        std::cout <<  _name << " is dead and can't attack!" << std::endl;
    else if (target._hitPoints <= 0)
    {
        if (_energyPoints)
            _energyPoints--;
        else
        {
            std::cout <<  _name << " doesn't have enough energy to attack!" << std::endl;
            return;
        }
        std::cout << _name << " tried to attack " << target._name << " but " << target._name << " is already dead!" << std::endl;
    }
    else if (!_attackDamage)
    {
        if (_energyPoints >= 0)
            _energyPoints--;
        else
        {
            std::cout << _name << " doesn't have enough energy to attack!" << std::endl;
            return;
        }
        std::cout << _name << " tried to attack but has no power!" << std::endl;
        std::cout << "No damage made!" << std::endl;
    }
    else
    {
        attack(target._name);
        target.takeDamage(_attackDamage);
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << _name << " is already dead!" << std::endl;
    return;
  }
  std::cout << _name << " takes " << amount << " points of damage";
  _hitPoints -= amount;
  if (_hitPoints <= 0) {
    _hitPoints = 0;
    std::cout << " and dies!" << std::endl;
    return;
  }
  std::cout << " and now has " << _hitPoints << " hitpoints!" << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount )
{
    if (_hitPoints == 0)
    {
        std::cout << _name << " is dead and can't be repaired!" << std::endl;
        return;
    }
    if (_energyPoints >= 0)
    {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << _name << " is repaired by " << amount << " points and now has " << _hitPoints << " hitpoints!" << std::endl;
    }
    else
        std::cout << _name << " doesn't have enough energy to be repaired!" << std::endl; 
}

void ClapTrap::setAttackDamage( unsigned int amount )
{
    _attackDamage = amount;
    std::cout << _name << " is preparing their fists. Their attack damage is at " << _attackDamage << std::endl;
}

void ClapTrap::status(void) const {
  std::cout << "Name: " << _name << "; HP: " << _hitPoints
            << "; EP: " << _energyPoints << "; ATT: " << _attackDamage
            << std::endl;
}
