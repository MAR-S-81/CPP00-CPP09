*This project has been created as part of the 42 curriculum by mchesnea.*

# C++ Modules (CPP00 - CPP09)

A comprehensive journey through Object-Oriented Programming, memory management, generic programming, and standard algorithms, strictly conforming to the **C++98** standard.

---

## General Constraints

- **Language Standard:** C++98, compiled with `c++ -Wall -Wextra -Werror -std=c++98`.
- **Memory Integrity:** Zero memory leaks allowed; verified with Valgrind / leaks.
- **Canonical Form:** Classes managing resources strictly implement Coplien's Orthodox Canonical Form (default constructor, copy constructor, copy assignment operator, and virtual destructor when inherited).
- **Restrictions:** No modern C++ features (C++11 and beyond), no `printf`/`malloc`/`free`, and no STL before Module 08.

---

## Modules Overview

| Module | Core Subject | Key Concepts |
| :--- | :--- | :--- |
| **CPP00** | Basic OOP & I/O Streams | Standard streams (`std::cin`, `std::cout`), namespaces, class declaration, member functions, `static` attributes. |
| **CPP01** | Memory & References | Dynamic allocation (`new`/`delete`), stack vs heap, references vs pointers, pointers to member functions. |
| **CPP02** | Orthodox Canonical Form | Operator overloading (arithmetic, comparison, insertion), fixed-point representation, Coplien's form. |
| **CPP03** | Inheritance | Base and derived classes, member access specifiers (`protected`), construction/destruction chaining, diamond problem. |
| **CPP04** | Subtype Polymorphism | Virtual functions, virtual destructors, dynamic dispatch (vtables), pure abstract classes, and interfaces. |
| **CPP05** | Exception Handling | Structured error handling using `try`/`catch`, custom exception classes deriving from `std::exception`. |
| **CPP06** | Type Casting | Explicit C++ cast operators: `static_cast`, `dynamic_cast`, `const_cast`, and `reinterpret_cast`. |
| **CPP07** | Templates | Function templates, class templates, generic data structures, explicit specialization. |
| **CPP08** | Containers & Iterators | Introduction to the Standard Template Library (STL): `std::vector`, `std::list`, iterators, and generic algorithms. |
| **CPP09** | Practical STL & Algorithms | Applied STL usage with strict container constraints: associative maps (`std::map`), stacks (`std::stack`), and Ford-Johnson sorting algorithm (`std::vector`, `std::deque`). |

---

## Build & Run

Every exercise includes its own `Makefile` with standard rules (`all`, `clean`, `fclean`, `re`).

Compile and run any exercise:

```bash
cd cpp04/ex00
make
./animal
```
