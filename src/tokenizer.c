#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @file tokenizer.c
 * Implements functions for tokenizing a string.
 * 
 * Functions:
 * - int space_char(char c): Checks if c is a printable whitespace character.
 * - int non_space_char(char c): Checks if c is not a whitespace character.
 * 
 * Author: Blaine
 * Last Edit: Oct 9, 2024
 */

/** Checks if c is a printable whitespace character. */
int space_char(char c) {
    return (c == ' ' || c == '\t');
}

/** non_space_char: Checks if c is not a whitespace character. */
int non_space_char(char c) {
    return (c != ' ' && c != '\t' && c != '\0');
}

/** Creates and returns a pointer to the first character in a token. */
char *token_start(char *str){
    // Moves on from leading spaces
    while (space_char(*str)) 
        str++;
    
    // Check if there's not a char
    if (*str == '\0') 
        return NULL;

    return str;
}

/** Returns a pointer terminator char following *token. */
char *token_terminator(char *token) {
    while (non_space_char(*token)) token++;
    return token;
}

/** Counts the number of tokens in the string argument. */
int count_tokens(char *str) {
    int count = 0;
    char *temp1 = token_start(str);

    while (temp1 != NULL) {
        count++;
        char *temp2 = token_terminator(temp1);
        temp1 = token_start(temp2);
    }

    return count;
}

/** Returns a fresh new zero-terminated string containing the number of chars from input string. */
char *copy_str(char *inStr, short len) {
    char *copy = (char *)malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len && inStr[i] != '\0'; i ++) {
        copy[i] = inStr[i];
    }

    copy[len] = '\0';
    return copy;
}

/** Tokenizes the input string into an array of strings. */
char **tokenize(char* str) { 
    int token_count = count_tokens(str);
    char **tokens = (char**)malloc((token_count + 1) * sizeof(char *));

    char *token = token_start(str); 
    int count = 0;

    while (token != NULL) {
        char *end = token_terminator(token);
        int len = end - token;

        // Copy tokens
        tokens[count] = copy_str(token, len);
        count++;

        token = token_start(end);
    }

    // Null terminate array and return
    tokens[count] = NULL;
    return tokens;
}


/** Prints all tokens. */
void print_tokens(char **tokens) {
    for (int i = 0; tokens[i] != NULL; i++){
        printf("%s\n", tokens[i]);
    }
}

/** Frees all tokens and the vector containing them. */
void free_tokens(char **tokens) {
    for (int i = 0; tokens[i] != NULL; i++){
        free(tokens[i]); // Free each token
    }
    free(tokens); // Free the array
}