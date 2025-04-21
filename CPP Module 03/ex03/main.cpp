#include "DiamondTrap.hpp"

int main() {
    std::cout << "===== Testing Inheritance in DiamondTrap =====" << std::endl;

    // Test 1: Ensure DiamondTrap can access FragTrap and ScavTrap methods
    DiamondTrap dt("DiamondWarrior");
    DiamondTrap dop("DiamondOpponent");

    std::cout << "\n--- Testing ClapTrap Methods ---" << std::endl;
    // From ClapTrap: Attack, status, takeDamage, beRepaired
    dt.status();  // Should print the status (ClapTrap method), hitpoints: 100(from FragTrap), energy: 50(from ScavTrap), attack: 30(from FragTrap)
    dt.attack("TargetDummy");  // Should use ScavTrap's attack, not ClapTrap's
    dt.attackTarget(dop);  // Should use ScavTrap's attack, not ClapTrap's
    dt.takeDamage(30);  // Should reduce hitpoints (ClapTrap method)
    dt.beRepaired(20);  // Should repair hitpoints (ClapTrap method)
    dt.status();  // Confirm updated stats

    std::cout << "\n--- Testing ScavTrap Methods ---" << std::endl;
    // From ScavTrap: guardGate, attack (verify that it’s not ClapTrap's attack)
    dt.guardGate();  // Should use ScavTrap's guardGate method
    dt.attack("TargetDummy2");  // Ensure it's ScavTrap's attack being used

    std::cout << "\n--- Testing FragTrap Methods ---" << std::endl;
    // From FragTrap: highFivesGuys
    dt.highFivesGuys();  // Should use FragTrap's high-five method

    std::cout << "\n--- Testing DiamondTrap-Specific Method ---" << std::endl;
    // Test DiamondTrap's own method whoAmI
    dt.whoAmI();  // Should print both ClapTrap name and DiamondTrap name

    // Test 3: Modifying attributes to ensure inheritance hierarchy is respected
    std::cout << "\n--- Testing DiamondTrap Atribution ---" << std::endl;
    dt.setAttackDamage(50);  // Modify the attack damage and ensure it sticks
    dt.status();  // Should reflect new attack damage
    std::cout << std::endl;

    std::cout << "\n--- Copying DiamondTrap (Copy Constructor) ---" << std::endl;

    DiamondTrap original("OriginalDT");
    original.status();  // Show the status of the original

    // Creating a copy of the original DiamondTrap
    DiamondTrap copy(original);  // This should invoke the copy constructor
    copy.status();  // Show the status of the copied object to ensure everything is copied

    std::cout << "\n--- Modifying the Copy ---" << std::endl;
    copy.setAttackDamage(70);  // Modify the copied object to check independence
    copy.takeDamage(30);  // Apply damage to the copy
    copy.status();  // Show the updated status of the copy

    std::cout << "\n--- Verifying Original Remains Unchanged ---" << std::endl;
    // Ensure the original object has not been affected by the changes to the copy
    original.status();  // The original should have the same stats as before
    std::cout << std::endl;

    // Step 7: Test DiamondTrap Assignment Operator
    std::cout << "== DiamondTrap Assignment Operator Test ==" << std::endl;
    DiamondTrap dia1;
    dia1 = dt;          // Assignment operator
    dia1.whoAmI();      // Check names of assigned DiamondTrap
    dia1.attack ("TargetDummy3");
    dia1.status();         // Check status of assigned DiamondTrap
    std::cout << std::endl;

    std::cout << "== Deal with undefined behaviour with pointers ==" << std::endl;
    ScavTrap* clapp = new DiamondTrap();
    delete clapp;
    std::cout << std::endl;

}