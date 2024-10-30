#include <stdio.h>

/**
 * @file uimain.c
 * @brief A simple user interface for a tokenizer.
 * 
 * Author: Blaine Wever
 * Last Edit: Oct 8, 2024
 */

/**
 * @brief is_Exit: Checks if the given string is equal to "exit".
 * 
 * @param str A pointer to the input string to be compared.
 * @return 1 if the input string is "exit", else return 0.
 */
int is_Exit(const char *str);

/**
 * @brief Main function: Initializes the user interface
 *
 * This function handles the input and outputs between the user and the program.
 * The interface prompts the user indicated by a '$' and echoes the input back to user.
 * The interface will end if the user inputs "exit".
 * 
 * @return 0 on successful termination of program.
 */
int main () {
    char userInput[100];
    while (1) {
        printf("$ ");
        fgets(userInput, sizeof(userInput), stdin);
        printf("%s", userInput);

        if (is_Exit(userInput) == 1) {
            break;
        }
    }
    return 0;
}

int is_Exit (const char *str) {
    const char *exit_str = "exit";
    int i = 0;

    while (exit_str[i] != '\0' && str[i] != '\0'){
        if (str[i] != exit_str[i]) {
            return 0; // return 0 if str is not "exit"
        }
        i++;
    }
    // return 1 if str is "exit"
    return 1;
}