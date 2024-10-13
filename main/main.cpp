
/**
 * @file main.cpp
 * @brief Main firmware file for the Witcher Badge.
 *
 * This file contains the setup and main loop for the Witcher Badge firmware.
 * It initializes the serial communication, processes serial input, and executes commands.
 */

#include "witcher.h"
#include "cli.h"
#include "led.h"

extern "C" void app_main() {
    CLI cli;
    LED statusled = LED(2);
    // Create tasks
    xTaskCreate(
        CLI::taskFunction,  // Task function
        "Serial CLI",       // Task name
        4096,               // Stack size
        &cli,               // Task parameters
        1,                  // Priority
        NULL                // Task handle
    );
    xTaskCreate(
        LED::taskFunction,  // Task function
        "Status LED",       // Task name
        4096,               // Stack size
        &statusled,         // Task parameters
        1,                  // Priority
        NULL                // Task handle
    )
    while (true) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}