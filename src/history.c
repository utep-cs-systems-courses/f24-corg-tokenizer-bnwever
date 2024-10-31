#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/**
 * @file history.c
 * @brief
 * 
 * Functions:
 * 
 * Author: Blaine Wever
 * Last Edit: Oct 27, 2024
 */

/**
 * @brief Represents an item in a linked list.
 * 
 * This stucture stores an integer ID, a string pointer,
 * and a pointer to the next item in the list.
 */
typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

/**
 * @brief Represents a linked list. 
 * 
 * This structure holds a pointer to the root item of the list. 
 */
typedef struct s_List {
  struct s_Item *root;
} List;

/** Initialize the linked list to keep a history. */
List* init_history() {

    // Dynamically allocate memory with size List
    List *history = (List*)malloc(sizeof(List));

    // Set root to Null since no Node has been created yet
    history -> root = NULL;

    return history; // returns list structure
}

/**  
 * @brief Adds a history item to the end of the list.
 * 
 * @param List* list - the linked list (the root)
 * @param char* str - the string to store
*/
void add_history(List *list, char *str) {

    // Create an item
    Item *newItem = (Item*)malloc(sizeof(Item));
    newItem -> str = str;
    newItem -> next = NULL;

    // Check if list is empty
    if (list -> root == NULL) {
      // If empty, set newItem as root and assign its id as 0
      newItem -> id = 0;
      list -> root = newItem;
      return;
    }

    // Traverse to end of list
    Item *current = list -> root; 
    while (current -> next != NULL) {
      current = current -> next;
    }
    
    // Add newItem to end of list and assign its id
    newItem -> id = current -> id + 1;
    current -> next = newItem;
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
    printf("Str = %d\n", current -> str);
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
  Item *current = list ->root;
  Item *next;

// Traverse through list while freeing memory
  while (current != NULL) {
    next = current -> next;
    free(current -> id);
    free(current -> str);
    current = next;
  }

  // Free the list
  free(list);
}