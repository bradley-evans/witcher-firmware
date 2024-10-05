# Define variables
PLATFORMIO = platformio
MONITOR_SPEED = 115200
DOCKER_IMAGE = witcher-firmware:latest
DOCKER_CMD = docker run --rm -v $(PWD):/usr/src/app -w /usr/src/app $(DOCKER_IMAGE)

# Default target
all: dockerbuild

# Build the project using Docker
dockerbuild:
	$(DOCKER_CMD) $(PLATFORMIO) run

.PHONY: dockerbuild