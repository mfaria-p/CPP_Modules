# C++ Templates Exercises

## Overview
This project is a series of exercises designed to deepen your understanding of templates in C++. Templates are a powerful feature of C++ that allow you to write generic and reusable code, enabling functions and classes to operate with different data types without rewriting the code for each type.

## Project Structure
The project is divided into three exercises:

### Exercise 00: Basic Templates
**Files:** `main.cpp`, `whatever.hpp`, `Makefile`

**Objective:** Implement and test basic template functions: `swap`, `min`, and `max`.

**Key Concepts:**
- Define and use function templates.
- Work with different data types including custom types.

**Example Usage:**
```cpp
int a = 2, b = 3;
::swap(a, b);
std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

std::string e = "apple", f = "banana";
::swap(e, f);
std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
std::cout << "max(e, f) = " << ::max(e, f) << std::endl;
```

---

### Exercise 01: Iterating with Templates
**Files:** `main.cpp`, `iter.hpp`, `Makefile`

**Objective:** Implement a template function `iter` that applies a given function to each element of an array.

**Key Concepts:**
- Pass function pointers to templates.
- Use templates with arrays and custom types.
- Handle both mutable and immutable arrays using function overloading.

**Example Usage:**
```cpp
int intArray[] = {1, 2, 3, 4, 5};
::iter(intArray, 5, printElement);
::iter(intArray, 5, incrementElement);
::iter(intArray, 5, printElement);

ComplexType complexArray[] = {ComplexType(10), ComplexType(20)};
::iter(complexArray, 2, printElement);
::iter(complexArray, 2, doubleElement);
::iter(complexArray, 2, printElement);
```

---

### Exercise 02: Template Classes
**Files:** `main.cpp`, `Array.hpp`, `Array.tpp`, `Makefile`

**Objective:** Implement a template class `Array` that mimics the behavior of a dynamic array.

**Key Concepts:**
- Define and implement template classes.
- Use exceptions in template classes (e.g., `OutOfLimitsException`).
- Explore constructors, destructors, copy constructors, and assignment operators.

**Example Usage:**
```cpp
Array<int> intArray(5);
for (unsigned int i = 0; i < intArray.size(); i++) {
    intArray[i] = i + 1;
}
std::cout << intArray[2] << std::endl;

Array<std::string> stringArray(3);
stringArray[0] = "apple";
stringArray[1] = "banana";
stringArray[2] = "cherry";
std::cout << stringArray[1] << std::endl;

try {
    std::cout << stringArray[5] << std::endl;
} catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
}
```

---

## Key Learning Outcomes
- Solid understanding of function and class templates.
- Ability to write generic, reusable, and type-safe code.
- Use templates with both primitive and user-defined types.
- Apply advanced concepts such as exception handling and operator overloading in template context.

---

