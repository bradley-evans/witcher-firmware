PLATFORMIO = platformio
MONITOR_SPEED = 115200
DOCKER_IMAGE = witcher-firmware:latest
DOCKER_CMD = docker run --rm -v $(PWD):/usr/src/app -w

$PHONY: dockerbuild

all: dockerbuild

dockerbuild:
	$(DOCKER_CMD) $(PLATFORMIO) run

$PHONY: dockerbuild