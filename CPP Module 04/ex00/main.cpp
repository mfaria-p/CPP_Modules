#include "includes/Animal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"

/*int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << "\nTest for the wrong Animal and the wrong Cat" << std::endl;

    WrongAnimal* Wr_animal = new WrongAnimal();
    WrongAnimal* Wr_cat = new WrongCat();
    Wr_cat->makeSound();
    Wr_animal->makeSound();
    delete Wr_animal;
    delete Wr_cat;
}*/

int main() 
{
    // 1. Testing the Animal class and polymorphism
    std::cout << "\n--- Testing Animal, Dog, and Cat classes ---" << std::endl;
    const Animal* meta = new Animal(); // Base Animal class
    const Animal* dog = new Dog();     // Polymorphism with Dog
    const Animal* cat = new Cat();     // Polymorphism with Cat

    // Test getType() method
    std::cout << dog->getType() << " makes a sound: ";
    dog->makeSound();  // Dog sound

    std::cout << cat->getType() << " makes a sound: ";
    cat->makeSound();  // Cat sound

    std::cout << meta->getType() << " makes a sound: ";
    meta->makeSound();  // Animal sound

    // Clean up memory
    delete meta;
    delete dog;
    delete cat;

    // 2. Testing WrongAnimal and WrongCat
    std::cout << "\n--- Testing WrongAnimal and WrongCat classes ---" << std::endl;
    WrongAnimal* wrongAnimal = new WrongAnimal();  // Base class
    WrongAnimal* wrongCat = new WrongCat();        // Derived class (without virtual)

    std::cout << wrongCat->getType() << " makes a sound: ";
    wrongCat->makeSound();  // Incorrect behavior, calls WrongAnimal::makeSound

    std::cout << wrongAnimal->getType() << " makes a sound: ";
    wrongAnimal->makeSound();  // Expected: WrongAnimal sound

    // Clean up memory
    delete wrongAnimal;
    delete wrongCat;
}