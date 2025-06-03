
# xpriv
[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

**Current Version:** v1.2  
**Changelog Summary:**
- v0.3: First Stable Release  
- v0.6: Grammar fixes, new syntax, CLI optimization  
- v0.7: More syntax, performance boost  
- v1.0: OS-global compatibility  
- v1.1: Added new syntax and grammar improvements
- v1.2: Added new syntaxes(GETENV, SOCKET etc.) **optimize builds**  
---

## 🔐 xpriv: A Minimal Privilege-Based CLI Language

**xpriv** is a lightweight, root-aware command-line programming language built for scripting privileged system-level tasks. It's minimal, yet powerful, allowing you to write root/admin-required scripts with a simplified syntax similar to high-level languages.

---

## ✨ Features

- 🛡️ `requires root` or `requires admin` directive to enforce privileged execution
- ⚙️ `syscall()` for invoking system commands
- 📝 `let` for variable declaration and assignment
- 🔁 `loop N times` syntax for iterations
- 📤 `print()` for console output
- 💡 Clean, human-readable syntax
- 🛠️ Written in **C** using **Flex** (lexer) and **Bison** (parser)

---

## 🚀 Quick Example

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

## 🛠️ Build Instructions

### Dependencies (on Termux or Linux):
```bash
pkg install flex bison clang cmake make
```

### Build the Project
```bash
make
```

### Run a Script
```bash
./build/xpriv script.xpriv
```

---

## 📦 Supported Platforms

| OS            | Architectures Supported                                  |
|---------------|-----------------------------------------------------------|
| **Windows**   | x86_64, ARM64, ARM32 (some limitations may apply)         |
| **Linux**     | x86_64, ARM, AArch64, MIPS, PPC, RISC-V, SPARC, s390x     |
| **macOS**     | x86_64, Apple Silicon (M1, M2 - ARM64)                    |
| **Android**   | x86_64, AArch64, x86, armeabi-v7a (via Termux)            |

---

## 🤔 Why xpriv?

**xpriv** was designed to bridge the power of low-level system access (like assembly/C) with the readability of high-level scripting. Ideal for hackers, sysadmins, or anyone who wants **real root-level scripting power** in a minimal and portable language.

> Uses UID 0 on Unix or `IsUserAnAdmin()` on Windows to verify root/admin.

---

## 💡 Roadmap

- More syntaxes for privilege control
- File system and memory manipulation features
- Built-in helper tools for auditing and security
- Cross-compilation support for embedded systems

---

## 👤 Author & Contributors

**Lead Developer:** JeckAsChristopher  
> I'm the solo creator, but contributions are welcome! Message me if you'd like to join the development.

---

## 📥 Installation Summary

```bash
make
./build/xpriv yourscript.xpriv
```

---

## 📢 Updates

xpriv receives updates regularly:
- 🐞 Bugfixes: every 1–2 days
- 🚀 Major features: every 2–3 weeks

# Stay tuned and star the repo if you're interested in low-level scripting done right!
