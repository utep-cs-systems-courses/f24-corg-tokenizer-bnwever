#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

/** 
 * Check if input is equal to "exit" 
 * 0-3 if not, 4 if equal to exit
 */
int isExit(char *str) {
    int i = 0;
    char *strExit = "exit";

    // Traverse and compare each char in userInput and 'exit'
        while (str[i] != '\0' && strExit[i] != '\0') {

        // Checks if chars are not equal
        if (str[i] != strExit[i]){
            return i; 
        }

        i++;
    }
    return i;
}

/** 
 * Checks if a char is a digit 
 * return 1 if true 0 if false
*/
int isDigit(char c) {
    return c >= '0' && c <= '9';
}

int getDigit(const char *str) {
    int res = 0;
    while (isDigit(*str)) {
        res = res * 10 + (*str - '0');
        str++;
    }
    return res;
}

int main() {

    // Initialize history
    List *hist = init_history();

    // char to hold user's input
    char usrInp[128];

    // Loop to keep program running as many times as needed
    while  (1) {

        // Receive the input from user
        printf("\n> ");
        fgets(usrInp, sizeof(usrInp), stdin);

        // remove newline from user input
        int j = 0;
        while (usrInp[j] != '\0') {
            if (usrInp[j] == '\n') {
                usrInp[j] = '\0';
                break;
            }
            j++;
        }

        // End program if userInput is "exit"
        if (isExit(usrInp) == 4) break;
        

        // Check if input is a command ('!' followed by a digit)
        if (usrInp[0] == '!' && isDigit(usrInp[1])){

            int id = getDigit(usrInp + 1);
            char *idHist = get_history(hist, id);

            // Check if there was a found history
            if (idHist) {
                printf("%s\n", idHist); // print history
            } else {
                printf("No history was found.\n");
            }
        }

        // If not 'exit' or a command, add string to history
        else {
            add_history(hist, usrInp);
            printf("%s\n", usrInp);
        }

    }

    // Free memory when program ends
    free_history(hist);
    return 0;
}