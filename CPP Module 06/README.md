# C++ Casting Module

## Overview

This project demonstrates the various types of casting in C++ through hands-on exercises. It covers:

- `static_cast`
- `reinterpret_cast`
- `dynamic_cast`
- `const_cast` (mentioned but not exemplified)

Each exercise (`ex00`, `ex01`, `ex02`) explores one or more casting techniques in practical examples.

---

## Exercise 00: Scalar Conversion

### Description

Converts a string scalar into various C++ types (`char`, `int`, `float`, `double`) using `static_cast`.

### Casting Used

- **`static_cast`**: Converts one fundamental type to another.

#### Example in `ScalarConverter.cpp`

```cpp
i = static_cast<int>(c);
f = static_cast<float>(c);
d = static_cast<double>(c);
```

### Key Files

- `ScalarConverter.hpp`
- `ScalarConverter.cpp`
- `main.cpp`

### How to Run

```bash
cd ex00
make
./convert [scalar_value]
```

---

## Exercise 01: Serialization and Deserialization

### Description

Converts a pointer to a `Data` structure into an integer type (`uintptr_t`) and vice versa using `reinterpret_cast`.

### Casting Used

- **`reinterpret_cast`**: Performs low-level pointer-to-integer and back conversions.

#### Example in `Serializer.cpp`

```cpp
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
```

### Key Files

- `Serializer.hpp`
- `Serializer.cpp`
- `Data.hpp`
- `main.cpp`

### How to Run

```bash
cd ex01
make
./serializer
```

---

## Exercise 02: Dynamic Casting and Polymorphism

### Description

Randomly generates an instance of class `A`, `B`, or `C` (derived from base class `Base`) and identifies its type using `dynamic_cast`.

### Casting Used

- **`dynamic_cast`**: Used for safe downcasting in class hierarchies.

#### Pointer-based check

```cpp
if (dynamic_cast<A *>(p)) {
    std::cout << "A" << std::endl;
} else if (dynamic_cast<B *>(p)) {
    std::cout << "B" << std::endl;
} else if (dynamic_cast<C *>(p)) {
    std::cout << "C" << std::endl;
}
```

#### Reference-based check with exception handling

```cpp
try {
    A &a = dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
} catch (std::exception &e) {
    // Not A
}
```

### Key Files

- `Base.hpp`
- `Base.cpp`
- `A.hpp`
- `B.hpp`
- `C.hpp`
- `main.cpp`

### How to Run

```bash
cd ex02
make
./base
```

---

## Key Learning Objectives

- Understand and apply C++ casting types:
  - `static_cast`
  - `reinterpret_cast`
  - `dynamic_cast`
- Identify safe vs unsafe casts and their use cases
- Gain experience with polymorphism and type safety

