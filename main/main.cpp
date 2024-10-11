#include "witcher.h"

char inputBuffer[MAX_INPUT_LENGTH];
int inputIndex = 0;

void setup() {
    Serial.begin(115200);
    Serial.println("Initializing Witcher Badge Firmware");
}

void executeCommand(const char *command) {
    Serial.print("Received command: ");
    Serial.println(command);
}

void processSerialInput() {
    if (Serial.available()) {
        char c = Serial.read();
        Serial.write(c);    // Echo the character
        if (c == '\n' || c == '\r') {
            inputBuffer[inputIndex] = '\0'; // Null-terminate the string
            executeCommand(inputBuffer);
            inputIndex = 0; // Reset the input buffer index
        } else if (inputIndex < MAX_INPUT_LENGTH - 1) {
            inputBuffer[inputIndex++] = c; // Add character to input buffer
        }
    }
}

void loop() {
    processSerialInput();
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}

extern "C" void app_main() {
    setup();
    while (true) {
        loop();
    }
}