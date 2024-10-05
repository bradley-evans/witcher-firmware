# Define variables
PLATFORMIO = platformio
MONITOR_SPEED = 115200
DOCKER_IMAGE = witcher-firmware:latest
DOCKER_CMD = docker run --rm -v $(pwd):/usr/src/app -w /usr/src/app $(DOCKER_IMAGE)

# Define the output directory for artifacts
ARTIFACTS_DIR = artifacts
OUTPUT_BINARY = .pio/build/esp32/firmware.bin

# Default target
all: dockerbuild

# Build the project using Docker
dockerbuild:
	$(DOCKER_CMD) $(PLATFORMIO) run --silent
	mkdir -p $(ARTIFACTS_DIR)
	cp $(OUTPUT_BINARY) $(ARTIFACTS_DIR)

test:
	$(DOCKER_CMD) qemu-system-xtensa -nographic -machine esp32 -drive file=$(OUTPUT_BINARY),if=mtd,format=raw

# Clean the project using Docker
clean:
	$(DOCKER_CMD) $(PLATFORMIO) run --target clean
	rm -rf $(ARTIFACTS_DIR)

.PHONY: dockerbuild test