/**
 * @file cli.cpp
 * @brief Command Line Interface (CLI) class implementation.
 * 
 * This file contains the implementation of the CLI class, which is used to process serial input.
 */
#include "cli.h"

CLI::CLI() : inputIndex(0) {
    // Constructor
}

void CLI::setup() {
    // Setup function
    Serial.begin(115200);
    Serial.println("Initializing Witcher Badge Firmware");
}

void CLI::processSerialInput() {
    // Process serial input function
    if (Serial.available()) {
        char c = Serial.read();
        Serial.write(c);    // Echo the character
        if (c == '\n' || c == '\r') {
            this->inputBuffer[this->inputIndex] = '\0'; // Null-terminate the string
            Serial.print("Received command: ");
            Serial.println(this->inputBuffer);
            this->executeCommand(this->inputBuffer);
            this->inputIndex = 0; // Reset the input buffer index
        } else if (this->inputIndex < MAX_INPUT_LENGTH - 1) {
            this->inputBuffer[this->inputIndex++] = c; // Add character to input buffer
        }
    }
}

void CLI::executeCommand(const char *command) {
    // Execute command function
    Serial.print("Executing command: ");
    Serial.println(command);
}

void CLI::taskFunction(void *pvParameters) {
    // Task function
    CLI *cli = (CLI *)pvParameters;
    cli->setup();
    while (true) {
        cli->processSerialInput();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}