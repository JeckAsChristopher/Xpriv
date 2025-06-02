# DO NOT MODIFY! Unless there's an error.
# LICENSE BY MIT
# SHADOW FOUNDATION 2025

# Configuration
BUILD_DIR := build
VERSION_FILE := version.txt
VERSION_OUTPUT := $(BUILD_DIR)/version

# Load environment variables if .env exists
ifneq ("$(wildcard .env)","")
  include .env
endif

# Detect platform
UNAME_S := $(shell uname -s)
IS_TERMUX := $(shell test -n "$$PREFIX" && echo yes || echo no)
IS_MINGW := $(findstring MINGW,$(UNAME_S))
IS_DARWIN := $(findstring Darwin,$(UNAME_S))

.PHONY: all check-deps mkdir-safe configure version build clean check version

# Default target
all: check-deps mkdir-safe configure version build

# Check required tools per platform
check-deps:
ifeq ($(IS_MINGW),MINGW)
	@where flex >nul 2>&1 || (echo Missing: flex. Install with: choco install winflexbison3 && exit /b 1)
	@where bison >nul 2>&1 || (echo Missing: bison. Install with: choco install winflexbison3 && exit /b 1)
	@where cmake >nul 2>&1 || (echo Missing: cmake. Install with: choco install cmake && exit /b 1)
else
	@command -v flex >/dev/null 2>&1 || { echo "\033[1;31mMissing: flex\033[0m. Install with: \033[1;32m$(if $(IS_TERMUX),pkg,$(if $(IS_DARWIN),brew,sudo apt)) install flex\033[0m"; exit 1; }
	@command -v bison >/dev/null 2>&1 || { echo "\033[1;31mMissing: bison\033[0m. Install with: \033[1;32m$(if $(IS_TERMUX),pkg,$(if $(IS_DARWIN),brew,sudo apt)) install bison\033[0m"; exit 1; }
	@command -v cmake >/dev/null 2>&1 || { echo "\033[1;31mMissing: cmake\033[0m. Install with: \033[1;32m$(if $(IS_TERMUX),pkg,$(if $(IS_DARWIN),brew,sudo apt)) install cmake\033[0m"; exit 1; }
endif

# Create build directory safely
mkdir-safe:
ifeq ($(IS_MINGW),MINGW)
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
else
	@mkdir -p $(BUILD_DIR)
endif

# Run CMake configure (no toolchain file)
configure:
	@cd $(BUILD_DIR) && cmake ..

# Build the project using CMake
build:
	@cd $(BUILD_DIR) && cmake --build .

# Clean build artifacts
clean:
ifeq ($(IS_MINGW),MINGW)
	@if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)
else
	@rm -rf $(BUILD_DIR)
endif

.PHONY: check version

check: version

version: mkdir-safe
ifeq ($(IS_MINGW),MINGW)
	@if not exist .env (echo "\033[1;33mWarning: .env file missing! Build may be non-verified.\033[0m")
	@if not exist $(VERSION_FILE) (echo "\033[1;31mError: version.txt not found!\033[0m" && exit /b 1)
	@for /F "tokens=2 delims=:" %%A in ('findstr "^Version:" $(VERSION_FILE)') do echo %%A > $(VERSION_OUTPUT)
	@set /p _ver=<$(VERSION_OUTPUT) & echo Building xpriv version:%_ver%
	@if exist .env (
		certutil -hashfile $(VERSION_FILE) SHA256 | findstr /i "$(CHECKSUM)" >nul && echo version.txt checksum OK. || echo "\033[1;33mWarning: Checksum invalid, non-verified build.\033[0m"
	) else (
		echo "\033[1;33mWarning: .env missing, skipping checksum verification.\033[0m"
	)
else
	@if [ ! -f .env ]; then \
		echo "\033[1;33mWarning: .env file missing! Build may be non-verified.\033[0m"; \
	fi
	@if [ ! -f $(VERSION_FILE) ]; then \
		echo "\033[1;31mError: version.txt not found!\033[0m"; exit 1; \
	fi
	@grep '^Version:' $(VERSION_FILE) | cut -d ':' -f2- | xargs > $(VERSION_OUTPUT)
	@echo "Building xpriv version: $(shell cat $(VERSION_OUTPUT))"
	@if [ -f .env ]; then \
		echo "$(CHECKSUM)  $(VERSION_FILE)" > $(BUILD_DIR)/version_checksum.txt; \
		sha256sum -c --status $(BUILD_DIR)/version_checksum.txt && echo "version.txt checksum OK." || echo "\033[1;33mWarning: Checksum invalid, non-verified build.\033[0m"; \
	else \
		echo "\033[1;33mWarning: .env missing, skipping checksum verification.\033[0m"; \
	fi
endif
