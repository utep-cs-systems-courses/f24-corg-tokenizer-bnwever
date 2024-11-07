#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

/**
 * @file uimain.c
 * A simple user interface for a tokenizer.
 * 
 * Author: Blaine
 * Last Edit: Oct 30, 2024
 */

/** Custom implementation of strcmp */
int strCompare(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

/** Custom implementation of strcspn */
size_t strcspn(const char *str, const char *reject) {
    const char *p;
    const char *r;

    for (p = str; *p != '\0'; p++) {
        for (r = reject; *r != '\0'; r++) {
            if (*p == *r) {
                return p - str;
            }
        }
    }
    return p - str;
}

/** Custom implementation of isdigit */
int isdigit(char c) {
    return (c >= '0' && c <= '9');
}

/** Custom implementation of atoi */
int atoi(const char *str) {
    int result = 0;
    while (isdigit(*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}

/** Main function: Initializes the user interface */
int main() {
    // Initialize history linked list
    List *history = init_history();

    char userInput[100];
    while (1) {
        // Receive input from user
        printf("\n> ");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = 0; // Remove newline

        // Check if input is 'exit' command
        if (strCompare(userInput, "exit") == 0) {
            break;
        }

        /* Check if input is a command ('!' followed by a digit) 
           If so, print history based on id inputted by user
        */
        if (userInput[0] == '!' && isdigit(userInput[1])) {
            int id = atoi(userInput + 1); // Convert digits after '!' to integer
            char *recall = get_history(history, id);

            // Checks if there is a history at id to print
            if (recall) {
                printf("%s\n", recall);
            } else {
                printf("No history found\n");
            }
        }
        // If not a command then record input into history
        else {
            add_history(history, userInput);
            printf("%s\n", userInput);
        }
    }

    free_history(history); // Free history when program ends
    return 0;
}