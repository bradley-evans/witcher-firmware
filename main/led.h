#ifndef LED_H
#define LED_H

#include "witcher.h"

/**
 * @class LED
 * @brief A class to handle LED operations.
 *
 * The LED class provides methods to control the LEDs on the Witcher badge.
 */
class LED {
    public:
        /**
         * @brief Constructor for the LED class.
         */
        LED();

        /**
         * @brief Sets up the LED.
         */
        void setup();

        /**
         * @brief Turns the LED on.
         */
        void turnOn();

        /**
         * @brief Turns the LED off.
         */
        void turnOff();

        /**
         * @brief Toggles the LED state.
         */
        void toggle();

    private:
        int pin; ///< Pin number for the LED.
        bool state; ///< Current state of the LED.