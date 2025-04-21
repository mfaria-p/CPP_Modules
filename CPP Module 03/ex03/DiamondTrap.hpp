#ifndef __DIAMONDTRAP_H__
#define __DIAMONDTRAP_H__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string _name;

public:
    DiamondTrap();
    DiamondTrap( const std::string _name );
    DiamondTrap(const DiamondTrap& obj);
    ~DiamondTrap();
    DiamondTrap &operator=(const DiamondTrap &obj);
    using ScavTrap::attack;
    void whoAmI( void );
};

#endif