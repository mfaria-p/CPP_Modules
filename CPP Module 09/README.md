# C++ STL Containers Project

This project consists of three exercises designed to deepen your understanding of C++ containers and their practical applications. Each exercise demonstrates the effective use of specific STL containers tailored to solve a particular problem efficiently.

---

## Exercise 00: Bitcoin Exchange

### Overview:
A Bitcoin exchange rate tracker that reads historical rates from a CSV file (`data.csv`) and allows users to query the Bitcoin value on specific dates using an input file. The application validates input dates, ensures values are valid, and manages errors effectively.

### Container Used: `std::map`

#### Why `std::map`?
- **Key-Value Storage**: Stores dates (`std::string`) as keys and exchange rates (`float`) as values.
- **Automatic Sorting**: Maintains dates in sorted order, enabling efficient range-based queries.
- **Unique Keys**: Guarantees no duplicate entries for dates.
- **Efficient Lookups**: Offers O(log n) time complexity, ideal for date-based queries using `lower_bound()`.

---

## Exercise 01: Reverse Polish Notation (RPN) Calculator

### Overview:
Implements a calculator that evaluates mathematical expressions in postfix notation. This approach simplifies parsing by using a stack to manage operands and operators.

### Container Used: `std::stack`

#### Why `std::stack`?
- **LIFO Behavior**: Naturally supports the RPN evaluation order, where operands are pushed and the most recent are used first.
- **Restricted Access**: Only allows access to the top, reducing error risk and enforcing correct logic.
- **Simplicity**: Lightweight container, minimal overhead, perfect match for this use case.

---

## Exercise 02: Merge-Insertion Sort (PmergeMe)

### Overview:
Implements a hybrid merge-insertion sort algorithm applied to different containers to analyze performance. It validates inputs, retains the original data, and compares sorted results and execution time for each container type.

### Containers Used:

#### `std::vector`
- **Dynamic Array**: Contiguous memory allows for efficient random access and iteration.
- **Cache-Friendly**: Optimized for CPU cache usage, improving sort performance.
- **Auto-Resizable**: Manages varying input sizes efficiently.

#### `std::deque`
- **Double-Ended Access**: Efficient for operations that insert/remove at both ends.
- **Flexibility**: Better suited for specific access patterns compared to `std::vector`.
- **Iterator Support**: Compatible with sorting algorithms and STL functions.
- **Slower in Larger Datasets**: `std::deque` is composed of non-contiguous memory blocks, which can reduce cache efficiency. As input size grows, the increased memory fragmentation leads to more cache misses and degraded performance compared to `std::vector`.

#### `std::set` (used in `main.cpp`)
- **Unique Elements**: Ensures no duplicates are retained during validation.
- **Automatic Sorting**: Elements remain ordered, aiding post-sort comparison.
- **Efficient Lookups**: Provides O(log n) complexity for presence checks.

---

## Summary of Container Choices

| Container    | Use Case                          | Key Benefits                                                             |
|--------------|------------------------------------|---------------------------------------------------------------------------|
| `std::map`   | Storing exchange rates by date     | Sorted keys, efficient lookups, uniqueness                               |
| `std::stack` | Evaluating RPN expressions         | LIFO structure, restricted access, simplicity                            |
| `std::vector`| Merge-insertion sort               | Cache-efficient, resizable, fast random access                           |
| `std::deque` | Merge-insertion sort (variant)     | Efficient front/back operations, iterator compatibility, but slower on large datasets due to poor cache locality |
| `std::set`   | Validating sorted output integrity | Unique elements, automatically sorted, fast existence checks             |

Each container was selected to best suit the computational and logical demands of the task at hand. Understanding these choices fosters better software design and container selection in real-world C++ development.

---
