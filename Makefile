# DO NOT MODIFY!
# LICENSE BY MIT                                  # SHADOW FOUNDATION 2025

# Build directory
BUILD_DIR := build
VERSION_FILE := version.txt
VERSION_OUTPUT := $(BUILD_DIR)/version

.PHONY: all configure build clean

UNAME_S := $(shell uname -s)

all: configure version build

configure:
ifeq ($(UNAME_S),Linux)
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake ..
endif
ifeq ($(UNAME_S),Darwin)
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake ..
endif
ifeq ($(findstring MINGW,$(UNAME_S)),MINGW)
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake ..
endif

version:
	@mkdir -p $(BUILD_DIR)
ifeq ($(UNAME_S),Linux)
	@grep '^Version:' $(VERSION_FILE) | cut -d ':' -f2- | xargs > $(VERSION_OUTPUT)
	@echo "Building xpriv version:`cat $(VERSION_OUTPUT)`"
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
