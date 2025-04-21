#ifndef EX03_FRAGTRAP_HPP
#define EX03_FRAGTRAP_HPP

#include "ClapTrap.hpp"

// its constructors, destructor and attack() will print different messages.
class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string _name);
    FragTrap(const FragTrap &obj);
    ~FragTrap();
    FragTrap &operator=(const FragTrap &obj);
    void highFivesGuys(void);
};
#endif