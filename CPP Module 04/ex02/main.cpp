#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    std::cout << std::endl;

    const int numAnimals = 6;
    Animal* animals[numAnimals];

    // 1. Fill the first half with Dog objects, the second half with Cat objects
    std::cout << "--- Creating Dogs and Cats ---" << std::endl;
    for (int i = 0; i < numAnimals / 2; i++) {
        animals[i] = new Dog();
        std::cout << std::endl;
    }
    for (int i = numAnimals / 2; i < numAnimals; i++) {
        animals[i] = new Cat();
        std::cout << std::endl;
    }

    // 2. Make sounds from all animals to ensure correct behavior
    std::cout << "\n--- Making Sounds from All Animals ---" << std::endl;
    for (int i = 0; i < numAnimals; i++) {
        animals[i]->makeSound();
    }

    // 3. Delete all animals and ensure proper destructor calls
    std::cout << "\n--- Deleting All Animals ---" << std::endl;
    for (int i = 0; i < numAnimals; i++) {
        delete animals[i];
        std::cout << std::endl;
    }

    // 4. Test deep copy: copy a Dog and Cat, ensuring it's a deep copy
    std::cout << "\n--- Testing Deep Copy for Dog and Cat ---" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Play fetch");
    std::cout << std::endl;

    Dog copyDog(originalDog);  // Copy constructor, deep copy of Brain
    std::cout << std::endl;

    // Modify the copy's brain, and check that the original's brain is unaffected
    copyDog.getBrain()->setIdea(0, "Chase the ball");

    std::cout << "Original Dog Brain[0]: " << originalDog.getBrain()->getIdea(0) << std::endl; // Should still be "Play fetch"
    std::cout << "Copy Dog Brain[0]: " << copyDog.getBrain()->getIdea(0) << std::endl;       // Should be "Chase the ball"
    std::cout << std::endl;

    // Test for Cat as well
    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "Climb the tree");
    std::cout << std::endl;

    Cat copyCat(originalCat);  // Copy constructor, deep copy of Brain
    std::cout << std::endl;

    // Modify the copy's brain, and check that the original's brain is unaffected
    copyCat.getBrain()->setIdea(0, "Sleep on the couch");

    std::cout << "Original Cat Brain[0]: " << originalCat.getBrain()->getIdea(0) << std::endl; // Should still be "Climb the tree"
    std::cout << "Copy Cat Brain[0]: " << copyCat.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    //const Animal *testAnimal = new Animal();
    // Animal class is now abstract and cannot be instaciated
}

