#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

// its constructors, destructor and attack() will print different messages.
class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string _name);
    FragTrap(const FragTrap &obj);
    ~FragTrap();
    FragTrap &operator=(const FragTrap &obj);
    void highFivesGuys(void);
    void attack( const std::string& target );
};
#endif