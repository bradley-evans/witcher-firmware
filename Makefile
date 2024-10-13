# Define variables
PLATFORMIO = platformio
MONITOR_SPEED = 115200
SERIAL_DEVICE = /dev/ttyUSB0
DOCKER_IMAGE_DEV = witcher-firmware-dev:latest
DOCKER_CMD = docker run -it --rm --device=$(SERIAL_DEVICE) --privileged -v $(shell pwd):/usr/src/app -w /usr/src/app $(DOCKER_IMAGE_DEV)


# Define the output directory for artifacts
ARTIFACTS_DIR = artifacts
OUTPUT_BINARY = .pio/build/esp32/firmware.bin

# Default target
all: dockerbuild

qemu:
	. /opt/esp/idf/export.sh && cd /usr/src/app && idf.py qemu

flash:
	. /opt/esp/idf/export.sh && cd /usr/src/app && idf.py flash

monitor:
	. /opt/esp/idf/export.sh && cd /usr/src/app && idf.py monitor

# Build the project using Docker
dockerbuild-qemu:
	$(DOCKER_CMD) make qemu
	mkdir -p $(ARTIFACTS_DIR)
	cp $(OUTPUT_BINARY) $(ARTIFACTS_DIR)

dockerbuild-flash:
	$(DOCKER_CMD) make flash

dockerbuild-monitor:
	$(DOCKER_CMD)  make monitor

test:
	$(DOCKER_CMD) qemu-system-xtensa -nographic -machine esp32 -drive file=$(OUTPUT_BINARY),if=mtd,format=raw

# Clean the project using Docker
clean:
	$(DOCKER_CMD) $(PLATFORMIO) run --target clean
	rm -rf $(ARTIFACTS_DIR)

.PHONY: dockerbuild test