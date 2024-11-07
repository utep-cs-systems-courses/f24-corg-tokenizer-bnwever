#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/** Initialize the linked list to keep a history. */
List* init_history() {
    List *history = (List*)malloc(sizeof(List));
    history->root = NULL;
    return history;
}

/** Adds a new item to the history linked list with a unique ID. */
void add_history(List *list, char *str) {
    if (!list) return;

    // Allocate memory for the new item
    Item *new_item = (Item*)malloc(sizeof(Item));
    if (!new_item) return;

    // Allocate memory for and copy the string
    int len = 0;
    while (str[len] != '\0') len++;
    new_item->str = (char*)malloc(len + 1);
    if (!new_item->str) {
        free(new_item);
        return;
    }
    for (int i = 0; i <= len; i++) {
        new_item->str[i] = str[i];
    }

    // Set ID and insert the new item
    new_item->id = (list->root) ? list->root->id + 1 : 0;
    new_item->next = list->root;
    list->root = new_item;
}

/** Retrieve the string stored in the node where Item->id == id. */
char *get_history(List *list, int id) {
    if (!list || !list->root) return NULL;

    Item *current = list->root;
    while (current) {
        if (current->id == id) {
            return current->str;
        }
        current = current->next;
    }
    return NULL;
}

/** Print the entire contents of the list. */
void print_history(List *list) {
    Item *current = list->root;
    while (current) {
        printf("ID = %d\n", current->id);
        printf("Str = %s\n", current->str);
        printf("|\n|\nv\n");
        current = current->next;
    }
}

/** Free the history list and the strings it references. */
void free_history(List *list) {
    if (!list) return;

    Item *current = list->root;
    Item *next;
    while (current) {
        next = current->next;
        free(current->str);
        free(current);
        current = next;
    }

    free(list);
}
