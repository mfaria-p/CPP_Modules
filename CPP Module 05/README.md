# C++ Exception Handling

This module focuses on mastering C++ exception handling and solidifying object-oriented programming principles through practical implementation. It combines system-level practices, custom exception design, and design pattern integration in a modular C++ codebase.

---

## 🧱 Core Concepts Demonstrated

### 🔁 Inheritance & Polymorphism

- Developed an abstract base class `AForm` and derived specialized forms:
  - `ShrubberyCreationForm`
  - `RobotomyRequestForm`
  - `PresidentialPardonForm`
- Enabled polymorphic behavior using `AForm*` pointers and references.
- Each form class implements its specific `execute()` method.

### 🧩 Abstract Classes & Interface Contracts

- Declared `AForm` as an abstract class with pure virtual functions.
- Enforced implementation contracts for all derived classes.
- Demonstrated strong interface design and separation of responsibilities.

### 🚨 Robust Exception Handling

- Defined custom exception classes:
  - `GradeTooHighException`
  - `GradeTooLowException`
  - `FormNotSignedException`
- Applied `try-catch` blocks to manage runtime errors and enforce validation logic.
- Ensured program stability by handling edge cases explicitly.

#### Usage Example:

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

- Demonstrates type-specific error handling.
- Ensures precise diagnostics and controlled failure responses.

#### Example Scenario: Signing Failure

```cpp
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 100);
        Form f1("ImportantForm", 50, 50);

        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;

        b1.signForm(f1);
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
```

---

## 🔐 Encapsulation & Data Integrity

- Protected critical attributes like `_name` and `_grade` with `private` access modifiers.
- Provided controlled access via public getter methods.
- Preserved object state and consistency.

## 🏷️ Operator Overloading

- Overloaded the `<<` operator for:
  - `Bureaucrat`
  - `Form`
- Enhanced output clarity for debugging and user feedback.

## 🧠 Dynamic Memory & Polymorphic Behavior

- Allocated objects with `new` for polymorphism.
- Ensured cleanup via `delete` to avoid memory leaks.
- Managed lifetimes safely and efficiently in a polymorphic context.

## 🏭 Factory Method Pattern

- Implemented a factory pattern in the `Intern` class.
- Enabled dynamic creation of forms based on input strings.
- Promoted scalability and decoupling of object creation logic.

---

## 🚀 Conclusion

This project served as a comprehensive exercise in writing robust, maintainable, and professional-grade C++ code. It reinforced best practices in:

- Exception safety
- Polymorphism and encapsulation
- Interface design
- Factory-based object creation

The result is a clean, scalable codebase with strong foundations in real-world C++ development.



---

This project was a deep dive into writing **professional-grade** C++ code, and it reinforced best practices in **object-oriented programming**, **memory management**, and **design patterns**.


