#ifndef _BST_H_
#define _BST_H_

#include "node.h"

#include <stdbool.h>
#include <stdlib.h>

typedef struct BST {
	node* root; //pointer to the tree root
} BST;

/**
 * Creates a BST
*/
BST* create_BST();

/**
 * Adds an element to the tree
 */

void* BST_add(node *root, void* key, void* val, int (*cmp)( void*,  void*));

/**
 * Prints each value in the tree
 */
void print_tree(BST *tree, void (*print_function)(void*));

/**
 * Frees the tree
 */
void free_tree(node *root, void (*free_key)(void *),void (*free_value)(void *));

/**
 * Searches the tree and returns the value associated with
 */
void* BST_get(node* root, void* key,int (*cmp)( void*,  void*));



#endif
