<div align="center">

# ⚙️ C++ Modules 00–06

**The 42 C++ piscine — from namespaces and classes to casts, templates and STL thinking.**

![Language](https://img.shields.io/badge/language-C%2B%2B-00599C?style=flat-square&logo=c%2B%2B)
![Build](https://img.shields.io/badge/build-make-427819?style=flat-square)
![Standard](https://img.shields.io/badge/C%2B%2B-98-00599C?style=flat-square)
![Stars](https://img.shields.io/github/stars/ifrankerem/cpps?style=flat-square)

</div>

---

## 📋 Table of Contents

- [About](#about)
- [Module Map](#module-map)
- [Getting Started](#getting-started)
- [Conventions](#conventions)
- [Layout](#layout)
- [What I Learned](#what-i-learned)
- [Author](#author)

---

## 📖 About

Six modules that rebuild C++ from scratch the hard way: no STL in the early
ones, hand-written classes, manual memory, and a compiler that only says
`-Wall -Wextra -Werror`. Each module is its own directory with its own
exercises, and the subject PDF is kept wherever the curriculum ships one.

---

## 🗺 Module Map

| Module | Focus | Exercises |
|---|---|---|
| `cpp00` | namespaces, classes, member functions, `std::iostream` | ex00, ex01 |
| `cpp01` | memory allocation, references vs pointers, file streams, function pointers | ex00–ex06 |
| `cpp02` | ad-hoc polymorphism, operator overloading, fixed-point numbers, Orthodox Canonical Form | ex00–ex03 |
| `cpp03` | inheritance — single, multiple and diamond cases | ex00–ex02 |
| `cpp04` | abstract classes, interfaces, virtual inheritance | ex00–ex02 |
| `cpp05` | exceptions, `try` / `catch` / `throw`, nested exception types | ex00–ex03 |
| `cpp06` | C-style casts vs `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast` | ex00–ex02 |

---

## 🚀 Getting Started

```bash
cd cpp00/ex00
make          # or: c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o ex00
./ex00
```

Every exercise is self-contained and carries its own `Makefile` with the usual
`all`, `clean`, `fclean` and `re` targets.

---

## 🧾 Conventions

- `-std=c++98` — no C++11 conveniences: no `auto`, no range-for, no `nullptr`.
- **Orthodox Canonical Form** on every class that manages resources: default
  constructor, copy constructor, copy assignment operator, destructor.
- Header guards against double inclusion; each class gets a header plus an
  implementation file.
- The build must run clean under `-Wall -Wextra -Werror`.

---

## 🗂 Layout

```
cpps/
├── cpp00/  namespaces, classes, stdio streams
├── cpp01/  memory, references, files, function pointers
├── cpp02/  polymorphism, operators, fixed point
├── cpp03/  inheritance
├── cpp04/  abstract classes and interfaces
├── cpp05/  exceptions
└── cpp06/  casts + en.subject.pdf
```

---

## 🧠 What I Learned

- Where a reference and a pointer actually differ, and which one the situation wants.
- Why the Orthodox Canonical Form exists, and what breaks without it.
- How virtual dispatch is implemented — vtables versus explicit `this`.
- Treating a failed `dynamic_cast` as a design smell rather than a bug.

---

## 👤 Author

**İrfan Kerem Arslan** — [@ifrankerem](https://github.com/ifrankerem)

---

## 📄 License

Built for the **42 Common Core** C++ modules. Shared for learning and portfolio purposes.

---

## 🙏 Acknowledgements

- [awesome-readme](https://github.com/matiassingers/awesome-readme) — structure inspiration for this README