# DO NOT MODIFY!
# LICENSE BY MIT
# SHADOW FOUNDATION 2025

# Build directory
BUILD_DIR := build
VERSION_FILE := version.txt
VERSION_OUTPUT := $(BUILD_DIR)/version

.PHONY: all configure build clean

all: configure version build

configure:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..

version:
	@mkdir -p $(BUILD_DIR)
	@grep '^Version:' $(VERSION_FILE) | cut -d ':' -f2- | xargs > $(VERSION_OUTPUT)
	@echo "Building xpriv version:`cat $(VERSION_OUTPUT)`"

build:
	cd $(BUILD_DIR) && cmake --build .

clean:
	rm -rf $(BUILD_DIR)
