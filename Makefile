# DO NOT MODIFY!
# LICENSE BY MIT                                  # SHADOW FOUNDATION 2025                          

# Build directory
BUILD_DIR := build
VERSION_FILE := version.txt                       
VERSION_OUTPUT := $(BUILD_DIR)/version

.PHONY: all check-deps configure build clean version

UNAME_S := $(shell uname -s)
IS_TERMUX := $(shell test -n "$$PREFIX" && echo yes || echo no)

all: check-deps configure version build

check-deps:
ifeq ($(UNAME_S),Linux)
ifeq ($(IS_TERMUX),no)
	@command -v flex >/dev/null 2>&1 || { echo "\033[1;31mMissing: flex\033[0m. Install with: \033[1;32msudo apt install flex\033[0m"; exit 1; }
	@command -v bison >/dev/null 2>&1 || { echo "\033[1;31mMissing: bison\033[0m. Install with: \033[1;32msudo apt install bison\033[0m"; exit 1; }
	@command -v cmake >/dev/null 2>&1 || { echo "\033[1;31mMissing: cmake\033[0m. Install with: \033[1;32msudo apt install cmake\033[0m"; exit 1; }
endif
ifeq ($(IS_TERMUX),yes)
	@command -v flex >/dev/null 2>&1 || { echo "\033[1;31mMissing: flex\033[0m. Install with: \033[1;32mpkg install flex\033[0m"; exit 1; }
	@command -v bison >/dev/null 2>&1 || { echo "\033[1;31mMissing: bison\033[0m. Install with: \033[1;32mpkg install bison\033[0m"; exit 1; }
	@command -v cmake >/dev/null 2>&1 || { echo "\033[1;31mMissing: cmake\033[0m. Install with: \033[1;32mpkg install cmake\033[0m"; exit 1; }
endif
endif

ifeq ($(UNAME_S),Darwin)
	@command -v flex >/dev/null 2>&1 || { echo "\033[1;31mMissing: flex\033[0m. Install with: \033[1;32mbrew install flex\033[0m"; exit 1; }
	@command -v bison >/dev/null 2>&1 || { echo "\033[1;31mMissing: bison\033[0m. Install with: \033[1;32mbrew install bison\033[0m"; exit 1; }
	@command -v cmake >/dev/null 2>&1 || { echo "\033[1;31mMissing: cmake\033[0m. Install with: \033[1;32mbrew install cmake\033[0m"; exit 1; }
endif

ifeq ($(findstring MINGW,$(UNAME_S)),MINGW)
	@where flex >nul 2>&1 || (echo Missing: flex. Please install via Chocolatey: choco install winflexbison3 && exit /b 1)
	@where bison >nul 2>&1 || (echo Missing: bison. Please install via Chocolatey: choco install winflexbison3 && exit /b 1)
	@where cmake >nul 2>&1 || (echo Missing: cmake. Please install via Chocolatey: choco install cmake && exit /b 1)
endif

configure:
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake ..

version:
	@mkdir -p $(BUILD_DIR)
ifeq ($(UNAME_S),Linux)
ifeq ($(IS_TERMUX),no)
	@grep '^Version:' $(VERSION_FILE) | cut -d ':' -f2- | xargs > $(VERSION_OUTPUT)
	@echo "Building xpriv version:`cat $(VERSION_OUTPUT)`"
endif
ifeq ($(IS_TERMUX),yes)
	@grep '^Version:' $(VERSION_FILE) | cut -d ':' -f2- | xargs > $(VERSION_OUTPUT)
	@echo "Building xpriv version:`cat $(VERSION_OUTPUT)`"
endif
endif
ifeq ($(UNAME_S),Darwin)
	@grep '^Version:' $(VERSION_FILE) | cut -d ':' -f2- | xargs > $(VERSION_OUTPUT)
	@echo "Building xpriv version:`cat $(VERSION_OUTPUT)`"
endif
ifeq ($(findstring MINGW,$(UNAME_S)),MINGW)
	@for /F "tokens=2 delims=:" %%A in ('findstr "^Version:" $(VERSION_FILE)') do echo %%A > $(VERSION_OUTPUT)
	@echo Building xpriv version:$(shell type $(VERSION_OUTPUT))
endif

build:
	@cd $(BUILD_DIR) && cmake --build .

clean:
ifeq ($(UNAME_S),Linux)
	@rm -rf $(BUILD_DIR)
endif
ifeq ($(UNAME_S),Darwin)
	@rm -rf $(BUILD_DIR)
endif
ifeq ($(findstring MINGW,$(UNAME_S)),MINGW)
	@rmdir /S /Q $(BUILD_DIR)
endif
