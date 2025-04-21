#include "ScavTrap.hpp"

int main() {
    // Step 1: Testing ScavTrap default constructor
    std::cout << "== ScavTrap Default Constructor Test ==" << std::endl;
    ScavTrap scav1;
    scav1.status();  // Check initial status
    std::cout << std::endl;

    // Step 2: Testing ScavTrap parameterized constructor
    std::cout << "== ScavTrap Parameterized Constructor Test ==" << std::endl;
    ScavTrap scav2("Scavenger");
    scav2.status();  // Check initial status

    std::cout << std::endl;

    // Step 3: Testing inherited attack function
    std::cout << "== Inherited Attack Function Test ==" << std::endl;
    ClapTrap clap1("Clappy");
    scav2.attackTarget(clap1);  // ScavTrap attacking ClapTrap
    scav2.attackTarget(scav1);  // ScavTrap attacking ScavTrap
    clap1.status();       // Check ClapTrap's status after attack
    scav2.status();       // Check ScavTrap's status after attack
    scav1.status();       // Check ScavTrap's status after attack

    std::cout << std::endl;

    // Step 4: Testing inherited takeDamage and beRepaired functions
    std::cout << "== Inherited TakeDamage and BeRepaired Test ==" << std::endl;
    scav2.takeDamage(30);  // ScavTrap taking damage
    scav2.status();        // Check status after taking damage

    scav2.beRepaired(20);  // ScavTrap repairing
    scav2.status();        // Check status after repair

    std::cout << std::endl;

    // Step 5: Testing ScavTrap-specific guardGate function
    std::cout << "== ScavTrap-Specific Function Test: guardGate ==" << std::endl;
    scav2.guardGate();  // Activate guard gate mode

    std::cout << std::endl;

    // Step 6: Test ScavTrap Copy Constructor
    std::cout << "== ScavTrap Copy Constructor Test ==" << std::endl;
    ScavTrap scav3(scav2);  // Copy constructor
    scav3.status();         // Check status of copied ScavTrap

    std::cout << std::endl;

    // Step 7: Test ScavTrap Assignment Operator
    std::cout << "== ScavTrap Assignment Operator Test ==" << std::endl;
    ScavTrap scav4;
    scav4 = scav2;          // Assignment operator
    scav4.status();         // Check status of assigned ScavTrap
    std::cout << std::endl;

    std::cout << "== Deal with undefined behaviour with pointers ==" << std::endl;
    ClapTrap* clapp = new ScavTrap();
    delete clapp;
    std::cout << std::endl;
}