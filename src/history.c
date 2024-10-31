#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/**
 * @file history.c
 * Implemented function for managing a history in a linked list.
 * 
 * Author: Blaine
 * Last Edit: Oct 30, 2024
 */

/** Initialize the linked list to keep a history. */
List* init_history() {
    List *history = (List*)malloc(sizeof(List));

    // Set root to Null since no Node has been created yet
    history -> root = NULL;

    return history; // returns list structure
}

void add_history(List *list, char *str) {
    if (!list) return;

    // Tokenize the input string
    char **tokens = tokenize(str);  // tokens array from tokenizer

    // Allocate memory for the new item
    Item *new_item = (Item*)malloc(sizeof(Item));
    if (!new_item) return;

    // Store the original string and tokens in new_item
    int len = 0;
    while (str[len] != '\0') len++;  // Calculate length of input string
    new_item->str = (char*)malloc(len + 1);
    if (!new_item->str) {
        free(new_item);
        return;
    }
    for (int i = 0; i <= len; i++) {
        new_item->str[i] = str[i];
    }

    // Set the ID and link the new item to the list
    new_item->id = (list->root) ? list->root->id + 1 : 0;
    new_item->next = list->root;
    list->root = new_item;

    // Free tokens after use, as they are no longer needed here
    free_tokens(tokens);
}


/** Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id) {

  // Check if list is empty
  if (list -> root == NULL) {
    return NULL;
  }

  // Traverse to item with requested id
  Item *current = list -> root;
  while (current -> id != id){
    current = current -> next;
  }

  // Return stored string of item
  return current -> str;
}

/** Print the entire contents of the list. */
void print_history(List *list) {
  Item *current = list -> root;
  while (current != NULL) {
    printf("ID = %d\n", current -> id);
    printf("Str = %s\n", current -> str);
    printf("|\n|\nv\n");
  }
}

/** Free the history list and the strings it references. */
void free_history(List *list) {
  // Check if list is empty
  if (list == NULL) {
    return;
  }

  // Temporary pointers to help traverse
  Item *current = list -> root;
  Item *next;

// Traverse through list while freeing memory
  while (current != NULL) {
    next = current -> next;
    free(current -> str);
    free(current);
    current = next;
  }

  // Free the list
  free(list);
}