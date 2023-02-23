/*******************************************************************************
 * Name        : node.c
 * Author      : Brian S. Borowski
 * Editor      : William Freedman
 * Date        : February 3, 2023
 * Description : Practice with pointers, function pointers, and the linked list.
 ******************************************************************************/
#include <stdlib.h>
#include "node.h"

node* create_node(void *key, void *value) {
    node *n = (node *)malloc(sizeof(node));
    if (n != NULL) {
        n->key = key;
        n->value = value;
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}

void free_node(node *n, void (*free_key)(void *),void (*free_value)(void *)) {
    free_key(n->key);
    free_value(n->value);
    free(n);
}