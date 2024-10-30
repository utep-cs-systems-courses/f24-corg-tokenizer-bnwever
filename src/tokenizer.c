#include <stdio.h>

/**
 * @file tokenizer.c
 * @brief Implements functions for tokenizing a string.
 * 
 * Functions:
 * - int space_char(char c): Checks if c is a printable whitespace character.
 * - int non_space_char(char c): Checks if c is not a whitespace character.
 * 
 * Author: Blaine Wever
 * Last Edit: Oct 8, 2024
 */

/**
 * @brief space_char: Checks if c is a printable whitespace character.
 * 
 * This function returns true if a character is whitespace such as '\t' or ' '.
 * Zero terminators are not printable (therefore false).
 * 
 * @param c The character to be checked.
 * @return int: 1(true) if c is whitespace, else return 0(false).
 */
int space_char(char c) {
    return (c == ' ' || c == '\t');
}

/**
 * @brief non_space_char: Checks if c is not a whitespace character.
 * 
 * This function returns false if a character is whitespace such as '\t' or ' '.
 * Zero terminators are non printable (therefore false).
 * 
 * @param c The character to be checked
 * @return int: 1(true) if c is not whitespace, else return 0(false)
 */
int non_space_char(char c) {
    return (c != ' ' || c != '\t' || c != '\0');
}

/**
 * @brief *token_start: Creates and returns a pointer to the first character in a token.
 * 
 * This function returns a pointer to the first character of the next space-seperated
 * token in zero-terminatedstr. Returns a Zero pointer if str has no tokens.
 * 
 * @param str A pointer to a string of tokens.
 * @return A pointer to the first character of the next token, or a zero pointer if no tokens.
 */
char *token_start(char *str){
    const char *meow = ' ';
    return meow;
}