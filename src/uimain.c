#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tokenizer.h"
#include "history.h"

/**
 * @file uimain.c
 * A simple user interface for a tokenizer.
 * 
 * Author: Blaine
 * Last Edit: Oct 30, 2024
 */

/** Main function: Initializes the user interface */
int main () {

    // Initialize history linked list
    List *history = init_history();

    char userInput[100];
    while (1) {
        // Receive input from user
        printf("> ");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = 0;

        // Check if input is 'exit' command
        if (strcmp(userInput, "exit") == 0) {
            break;
        }

        /* Check if input is a command ('!' followed by a digit) 
           If so, print history based on id inputed by user
        */
        if (userInput[0] == '!' && isdigit(userInput[1])) {
            int id = atoi(userInput + 1); // Atoi gets the entire num and cleans it. (use a for loop if not using atoi)
            char *recall = get_history(history, id);

            // Checks if there is a history at id to print
            if (recall) {
                printf("%s", recall);
            } else {
                printf("No histroy found");
            }
        }
        // If not a command then record input into history
        else {
            add_history(history, userInput);
            printf("%s", userInput);
        }
    }

    free_history(history); // Free history when program ends
    return 0;
}