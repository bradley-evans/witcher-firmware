#include "led.h"

LED::LED(int pin) : state(false) {
    // Constructor
    this->pin = pin;
}

void LED::setup() {
    // Setup function
    pinMode(this->pin, OUTPUT);
    this->turnOff();
}

void LED::turnOn() {
    // Turn on function
    digitalWrite(this->pin, HIGH);
    this->state = true;
}

void LED::turnOff() {
    // Turn off function
    digitalWrite(this->pin, LOW);
    this->state = false;
}

void LED::toggle() {
    // Toggle function
    if (this->state) {
        this->turnOff();
    } else {
        this->turnOn();
    }
}

void LED::cycle() {
    // Cycle function
    this->turnOn();
    vTaskDelay(500 / portTICK_PERIOD_MS);
    this->turnOff();
    vTaskDelay(500 / portTICK_PERIOD_MS);
}

void LED::taskFunction(void *pvParameters) {
    // Task function
    LED *led = (LED *)pvParameters;
    led->setup();
    while (true) {
        led->cycle();
    }
}