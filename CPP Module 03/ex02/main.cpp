#include "FragTrap.hpp"

int main() {
    // Step 1: Testing FragTrap default constructor
    std::cout << "== FragTrap Default Constructor Test ==" << std::endl;
    FragTrap frag1;
    frag1.status();  // Check initial status

    std::cout << std::endl;

    // Step 2: Testing FragTrap parameterized constructor
    std::cout << "== FragTrap Parameterized Constructor Test ==" << std::endl;
    FragTrap frag2("Fraggy");
    frag2.status();  // Check initial status

    std::cout << std::endl;

    // Step 3: Testing inherited attack function
    std::cout << "== Inherited Attack Function Test ==" << std::endl;
    ClapTrap clap1("Clappy");
    frag2.attackTarget(clap1);  // FragTrap attacking ClapTrap
    frag2.attackTarget(frag1);  // FragTrap attacking FragTrap
    clap1.status();       // Check ClapTrap's status after attack
    frag2.status();       // Check FragTrap's status after attack

    std::cout << std::endl;

    // Step 4: Testing inherited takeDamage and beRepaired functions
    std::cout << "== Inherited TakeDamage and BeRepaired Test ==" << std::endl;
    frag2.takeDamage(30);  // FragTrap taking damage
    frag2.status();        // Check status after taking damage

    frag2.beRepaired(20);  // FragTrap repairing
    frag2.status();        // Check status after repair

    std::cout << std::endl;

    // Step 5: Testing FragTrap-specific highFivesGuys function
    std::cout << "== FragTrap-Specific Function Test: highFivesGuys ==" << std::endl;
    frag2.highFivesGuys();  // FragTrap asking for a high-five

    std::cout << std::endl;

    // Step 6: Test FragTrap Copy Constructor
    std::cout << "== FragTrap Copy Constructor Test ==" << std::endl;
    FragTrap frag3(frag2);  // Copy constructor
    frag3.status();         // Check status of copied FragTrap

    std::cout << std::endl;

    // Step 7: Test FragTrap Assignment Operator
    std::cout << "== FragTrap Assignment Operator Test ==" << std::endl;
    FragTrap frag4;
    frag4 = frag2;          // Assignment operator
    frag4.status();         // Check status of assigned FragTrap
    std::cout << std::endl;

    std::cout << "== Deal with undefined behaviour with pointers ==" << std::endl;
    ClapTrap* clapp = new FragTrap();
    delete clapp;
    std::cout << std::endl;

    return 0;
}