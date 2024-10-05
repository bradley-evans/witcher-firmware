FROM espressif/idf:release-v4.4

WORKDIR /usr/src/app

ENV DEBIAN_FRONTEND=noninteractive

RUN pip install platformio
RUN platformio platform install espressif32 --with-package framework-arduinoespressif32
RUN apt-get -y -q update && apt-get install -y -q \
    libgcrypt20 \
    libglib2.0-0 \
    libpixman-1-0 \
    libslirp0 \
    python3-venv \
    pkg-config \
    libglib2.0-dev

RUN git clone https://github.com/espressif/qemu.git /usr/src/qemu-esp32

WORKDIR /usr/src/qemu-esp32
RUN mkdir -p /usr/src/qemu-esp32/build ; \
    cd /usr/src/qemu-esp32/build ; \
    ../configure --target-list=xtensa-softmmu ; \
    make -j$(nproc) ; \
    make install
RUN python /opt/esp/idf/tools/idf_tools.py install qemu-xtensa qemu-riscv32 ; \
    . /opt/esp/idf/export.sh


COPY . /usr/src/app/

WORKDIR /usr/src/app
RUN platformio run --silent

WORKDIR /usr/src/app