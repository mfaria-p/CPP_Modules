## What I Learned

This module is designed to help you understand Try/Catch and Exceptions in C++, and it helped me master several key C++ concepts, combining object-oriented programming with design patterns and system-level coding practices.

---

### 📚 Inheritance & Polymorphism

- Built a base abstract class `AForm` and derived specialized forms (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`).
- Used **polymorphism** to treat different forms uniformly through `AForm*` pointers and references.
- Ensured each form implements its own `execute()` behavior.

### 🔹 Abstract Classes & Pure Virtual Functions

- Defined `AForm` with **pure virtual functions** to force derived classes to implement specific methods.
- Gained deeper understanding of **abstract classes** and how they enforce interface consistency.

### 🚨 Exception Handling

- Created custom exceptions:
  - `GradeTooHighException`
  - `GradeTooLowException`
  - `FormNotSignedException`
- Used `try-catch` blocks for safer and more controlled error handling.

#### How to Use Try/Catch in C++

You wrap the risky code inside a `try` block, and use one or more `catch` blocks to handle specific exception types:

```cpp
try {
    Bureaucrat b("Alice", 1);
    AForm* form = new PresidentialPardonForm("Bob");
    form->beSigned(b);
    form->execute(b);
    delete form;
} catch (const AForm::FormNotSignedException& e) {
    std::cerr << "Form error: " << e.what() << std::endl;
} catch (const Bureaucrat::GradeTooLowException& e) {
    std::cerr << "Grade error: " << e.what() << std::endl;
} catch (const std::exception& e) {
    std::cerr << "Unhandled exception: " << e.what() << std::endl;
}
```

- Each `catch` block matches a specific exception type.
- The `what()` method gives a human-readable message.
- This lets the program continue running instead of crashing.

#### Example: Exception Handling with `try-catch`

The following example demonstrates how exceptions are handled when a `Bureaucrat` tries to sign a `Form` but does not meet the required grade:

```cpp
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 100);
        Form f1("ImportantForm", 50, 50);

        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;

        // Attempt to sign the form
        b1.signForm(f1);
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
```

- If `b1` does not have a high enough grade to sign `f1`, an exception is thrown and caught in the `catch` block.
- This pattern ensures robust and readable error handling logic in real-world C++ code.

### 🔐 Encapsulation

- Protected important class attributes (`_name`, `_grade`) by making them `private`.
- Provided controlled access through getter methods.
- Maintained object integrity by enforcing immutability where appropriate (e.g., bureaucrat names).

### 🏋️ Operator Overloading

- Overloaded the `<<` operator for both `Bureaucrat` and `Form` classes.
- Enabled intuitive and readable output to standard streams.

### 🔄 Dynamic Memory Management

- Allocated `Form` objects dynamically using `new`.
- Properly deallocated memory with `delete` to avoid leaks.
- Practiced managing lifetimes of polymorphic objects.

### 📈 Factory Method Pattern

- Implemented the **Factory Method Pattern** within the `Intern` class.
- Created different form types dynamically based on input string values.
- Achieved greater code flexibility and separation of concerns.

### 🏓 Code Organization

- Split code into multiple `.hpp` and `.cpp` files, each class having its own dedicated files.
- Automated compilation with a clean `Makefile`.
- Followed a modular, maintainable, and scalable project structure.

---

This project was a deep dive into writing **professional-grade** C++ code, and it reinforced best practices in **object-oriented programming**, **memory management**, and **design patterns**.


