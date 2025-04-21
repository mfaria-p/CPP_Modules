# C++ Module 04: Inheritance and Polymorphism

This project is part of the C++ modules designed to deepen understanding of object-oriented programming concepts in C++. Specifically, this module focuses on **inheritance**, **polymorphism**, and the use of **virtual functions**. Through a series of exercises, I implemented a hierarchy of classes to explore these concepts and their practical applications.

---

## Project Structure

The project is divided into three exercises (`ex00`, `ex01`, and `ex02`), each building upon the previous one:

### **Exercise 00: Basic Inheritance**
- Implemented a base class `Animal` and derived classes `Dog` and `Cat`.
- Introduced the concept of **virtual functions** to allow polymorphic behavior.
- Added `WrongAnimal` and `WrongCat` classes to demonstrate the importance of virtual functions.
- Key takeaway: Without a virtual destructor, deleting a derived class object through a base class pointer can lead to resource leaks or undefined behavior.

### **Exercise 01: Deep Copy and Resource Management**
- Added a `Brain` class used by `Dog` and `Cat`.
- Implemented **deep copy constructors** and **assignment operators**.
- Key takeaway: Properly managing dynamically allocated resources avoids memory leaks and incorrect behavior during copying.

### **Exercise 02: Abstract Classes**
- Made `Animal` an abstract class by introducing a **pure virtual function** (`makeSound`).
- Used abstract classes to test polymorphism with arrays of base class pointers.
- Key takeaway: Abstract classes enforce implementation of specific behavior in derived classes.

---

## What I Learned (With Examples)

### 1. **Inheritance**
Learned how to derive classes using the `:` syntax:
```cpp
class Animal {
public:
    void speak() const;
};

class Dog : public Animal {
public:
    void wagTail() const;
};
```
- Used `public` inheritance to ensure `Dog` has access to `Animal`'s public members.
- Learned that `protected` members can be accessed in derived classes:
```cpp
class Animal {
protected:
    std::string name;
};
```

### 2. **Polymorphism**
Understood how virtual functions allow dynamic dispatch:
```cpp
class Animal {
public:
    virtual void makeSound() const;
    virtual ~Animal(); // crucial for proper cleanup
};

class Dog : public Animal {
public:
    void makeSound() const;
};
```
- Demonstrated that base class pointers can call the correct overridden function:
```cpp
Animal* pet = new Dog();
pet->makeSound(); // Calls Dog's version
```

### 3. **Abstract Classes**
Learned how to define a class with a pure virtual function:
```cpp
class Animal {
public:
    virtual void makeSound() const = 0; // pure virtual
    virtual ~Animal();
};
```
- Abstract classes cannot be instantiated:
```cpp
Animal a; // Error: cannot instantiate abstract class
```
- All derived classes must implement the pure virtual function:
```cpp
class Cat : public Animal {
public:
    void makeSound() const;
};
```

### 4. **Resource Management (Rule of Three)**
Implemented deep copy constructors and assignment operators:
```cpp
class Brain {
private:
    std::string* ideas;
public:
    Brain();
    Brain(const Brain& other); // deep copy
    Brain& operator=(const Brain& other); // deep assignment
    ~Brain();
};
```
- Ensured each `Dog` or `Cat` manages its own copy of `Brain`:
```cpp
Dog d1;
Dog d2 = d1; // copies d1's Brain, not pointer
```
- Avoided shallow copies that would lead to double deletion.
---

By working through these exercises, I not only reinforced core object-oriented principles but also learned how to write safer and more maintainable C++ code by applying best practices like the Rule of Three, abstract base classes, and proper class hierarchy design.

