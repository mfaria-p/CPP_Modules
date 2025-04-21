#include "ClapTrap.hpp"

int main() {
    // Step 1: Basic creation tests
    std::cout << "== Creating ClapTraps ==" << std::endl;
    ClapTrap clap1("Clap1");
    ClapTrap clap2("Clap2");
    ClapTrap clap3; // Testing default constructor

    // Display initial status
    clap1.status();
    clap2.status();
    clap3.status();

    std::cout << std::endl;

    // Step 2: Test attacking another ClapTrap
    std::cout << "== Attack Tests ==" << std::endl;
    clap1.setAttackDamage(3);
    clap2.setAttackDamage(5);
    std::cout << std::endl;

    // Clap1 attacks Clap2
    clap1.attackTarget(clap2);
    clap2.status();  // Check if damage was applied to Clap2
    std::cout << std::endl;

    // Clap2 attacks Clap1
    clap2.attackTarget(clap1);
    clap1.status();  // Check if damage was applied to Clap1

    std::cout << std::endl;

    // Test attack on a target by name (not another ClapTrap object)
    clap1.attack("Target Dummy");
    std::cout << std::endl;

    // Step 3: Test self-repair with energy
    std::cout << "== Repair Tests ==" << std::endl;
    clap1.beRepaired(5); // Repair Clap1
    clap1.status();       // Check Clap1's status after repair
    std::cout << std::endl;

    clap2.beRepaired(2); // Repair Clap2
    clap2.status();       // Check Clap2's status after repair

    std::cout << std::endl;

     // Step 4: Test energy depletion
    std::cout << "== Energy Depletion Test ==" << std::endl;
    ClapTrap clap4("Clap4");

    // Set attack damage and attack multiple times to deplete energy
    clap4.setAttackDamage(2);

    for (int i = 0; i < 11; ++i) {
        clap4.attackTarget(clap2); // Should deplete energy after multiple attacks
    }
    std::cout << std::endl;

    // Step 5: Test repairing a dead ClapTrap
    std::cout << "== Repairing Dead ClapTrap Test ==" << std::endl;
    clap2.beRepaired(10); // Try to repair a dead ClapTrap
    clap2.status();       // Status should show no change as Clap5 is dead

    std::cout << std::endl;

    // Step 6: Test multiple ClapTraps attacking each other
    std::cout << "== Multiple ClapTrap Attack Test ==" << std::endl;
    ClapTrap clap5("Clap5");
    clap5.setAttackDamage(5);
    ClapTrap clap6("Clap6");
    clap6.setAttackDamage(4);

    clap6.attackTarget(clap1); // Clap6 attacks Clap1
    clap1.attackTarget(clap6); // Clap1 retaliates
    clap5.attackTarget(clap6); // Clap5 joins the attack
    clap6.status();      // Check Clap6's status after being attacked by multiple ClapTraps

    std::cout << std::endl;
}