#ifndef _TOKENIZER_
#define _TOKENIZER_

/**
 * @file tokenizer.h
 * @brief A header file for the tokenizer module
 * 
 * Last Edit: Oct 8, 2024
 */

/**
 * @brief space_char: Checks if c is a whitespace character.
 * 
 * @param c The character to be checked.
 * @return int: 1(true) if c is whitespace, else return 0(false).
 */
int space_char(char c);

/**
 * @brief non_space_char: Checks if c is not a whitespace character.
 * 
 * @param c The character to be checked
 * @return int: 1(true) if c is not whitespace, else return 0(false)
 */
int non_space_char(char c);

/**
 * @brief *token_start: Creates and returns a pointer to the first character in a token.
 * 
 * This function returns a pointer to the first character of the next space-seperated
 * token in zero-terminatedstr. Returns a Zero pointer if str has no tokens.
 * 
 * @param str A pointer to a string of tokens.
 * @return A pointer to the first character of the next token, or a zero pointer if no tokens.
 */
char *token_start(char *str); 

/* Returns a pointer terminator char following *token */
/**
 * @brief *token_terminator: Returns a pointer terminator char following *token
 * 
 * @param token Pointer to a token
 * @return Pointer terminator
 */
char *token_terminator(char *token);

/**
 * @brief count_tokens: Counts the number of tokens in the string argument.
 * 
 * @param str Pointer to a string of tokens
 * @return Number of tokens in string
 */
int count_tokens(char *str);

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
/**
 * @brief Returns a fresh new zero-terminated string containing the number of chars from input string.
 * 
 * @param inStr Pointer to input string.
 * @param len Number of chars to copy from input string.
 * @return char* Pointer to new zero-terminated string.
 */
char *copy_str(char *inStr, short len);

/**
 * @brief Tokenizes the input string into an array of strings.
 * 
 * For example, tokenize("hello world string") would result in:
 *    tokens[0] = "hello"
 *    tokens[1] = "world"
 *    tokens[2] = "string" 
 *    tokens[3] = 0
 * 
 * @param str Pointer to the input string to be tokenized.
 * @return char** A freshly allocated array of tokens.
 */
char **tokenize(char* str);

/* Prints all tokens. */
/**
 * @brief Prints all tokens
 * 
 * @param tokens A zero-terminated array of strings
 */
void print_tokens(char **tokens);

/**
 * @brief Frees all tokens and the vector containing them.
 * 
 * @param tokens A zero-terminated array of strings
 */
void free_tokens(char **tokens);

#endif