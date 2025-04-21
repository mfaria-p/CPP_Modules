#ifndef SCAVTRAP_HPP
#define SCAVTRA_HPP

#include "ClapTrap.hpp"

// its constructors, destructor and attack() will print different messages.
class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string _name);
    ScavTrap(const ScavTrap &obj);
    ~ScavTrap();
    ScavTrap &operator=(const ScavTrap &obj);
    void guardGate( void );
    void attack( const std::string& target );
};
#endif