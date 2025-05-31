# xpriv

[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

**Version:** v0.3 - First Stable Release
**Version:** v0.6 - Fix grammar and syntaxes(and also added new syntaxes and optimized the CLI)

---

## 🔐 xpriv: A Minimal Privilege-Based CLI Language

**xpriv** is a minimal, root-aware command-line programming language designed for scripting privileged operations, with built-in syntax for requiring root access, invoking system calls, declaring variables, and running loops.

---

## ✨ Features

- 🛡️ `requires root` directive to enforce root-only execution
- ⚙️ `syscall()` for executing system-level commands
- 📝 `let` syntax for variable declaration and assignment
- 🔁 `loop N times` for simple iteration blocks
- 📤 `print()` for output
- 🎯 Written in C using Flex (lexer) and Bison (parser)

---

## ⚙️ Build Instructions

You need `cmake`, `flex`, `bison`, and `clang` or `gcc`.

```bash
pkg install flex bison clang cmake make
make
```

## Usage
```Bash
./build/xpriv script.xp
```

## Example Script.xpriv
```xpriv

requires root

let cmd = "ls /root"
print(cmd)

syscall cmd

loop 3 times {
    print("Looping...")
}
```

---


## Inspiration

### This Design is like a low-level programming language. assembly. but this is meant for people who likes high level too much or normal people.
**This design uses UID 0(ROOT LEVEL ACCESS)**

> Stay tune for updates. updates always often big or normal
> This language is updating always. 2-3 weeks if it's big. 1-2 days if only bugs.

---

## Contributors

**JeckAsChristopher**(Lead Developer)
> Im the only who create this. but if you want to contribute just ask out!

## Installation

```Bash
Make
```
# Xpriv
