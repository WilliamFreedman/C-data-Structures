#include <stdlib.h>
#include "node.h"

typedef struct BST {
    struct node* root;
    int num_nodes;
    int (*key_cmp)(void*,void*);
} BST;

BST* create_BST(int (*key_comp)(void*,void*));

void free_BST(BST* tree);

int isEmpty(BST* tree);

int depth(BST* tree);

void* find(BST* tree, void* key_val);

void* add(BST* tree, void* key_val, void* val);

void* tree_remove(BST* tree, void* key_val);

int contains(BST* tree, void* key_val);

void level_order(BST* tree, void (*toRun)(node*));

void inorder(BST* tree, void (*toRun)(node*));

void preorder(BST* tree, void (*toRun)(node*));

void postorder(BST* tree, void (*toRun)(node*));

