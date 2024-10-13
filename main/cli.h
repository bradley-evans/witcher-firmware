
/**
 * @file cli.h
 * @brief Command Line Interface (CLI) header file for Witcher firmware.
 *
 * This file contains the declaration of the CLI class, which is responsible
 * for handling serial input and executing commands in the Witcher firmware.
 */

#ifndef CLI_H
#define CLI_H

#include "witcher.h"

#define MAX_INPUT_LENGTH 64 ///< Maximum length of the input buffer.

/**
 * @class CLI
 * @brief A class to handle command line interface operations.
 *
 * The CLI class provides methods to set up the CLI, process serial input,
 * and execute commands. It also includes a static task function for
 * FreeRTOS task management.
 */
class CLI {
    public:
        /**
         * @brief Constructor for the CLI class.
         */
        CLI();

        /**
         * @brief Sets up the CLI.
         */
        void setup();

        /**
         * @brief Processes serial input.
         */
        void processSerialInput();

        /**
         * @brief Task function for FreeRTOS.
         * @param pvParameters Parameters for the task function.
         */
        static void taskFunction(void *pvParameters);

    private:
        char inputBuffer[MAX_INPUT_LENGTH]; ///< Buffer to store input characters.
        int inputIndex; ///< Index to keep track of the current position in the input buffer.

        /**
         * @brief Executes a command.
         * @param command The command to execute.
         */
        void executeCommand(const char *command);
};

#endif // CLI_H