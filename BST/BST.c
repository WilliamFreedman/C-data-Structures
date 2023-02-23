#include <stdlib.h>
#include "BST.h"

BST *create_BST(void *root_key, void *val_key)
{
    node* new_root = create_node(root_key,val_key);
    BST* new_tree = (BST*) malloc(sizeof(BST));
    return new_tree;
}

void* BST_add(node* root, void* key, void* val, int (*cmp)( void*,  void*))
{
        if(cmp(root->key,key)> 0)
        {
            if (root->right == NULL)
            {
                root->right = create_node(key,val);
            }
            else
            {
                return add(root->right, key,val, cmp);
            }
        }
        else if (cmp(root->key,key)< 0)
        {
            if (root->left == NULL)
            {
                root->left = create_node(key,val);
            }
            else
            {
                return add(root->left, key,val, cmp);
            }
        }
        else
        {
            root->value = val;
        }
}

void free_tree(node* root,void (*free_key)(void *),void (*free_value)(void *))
{
    if (root == NULL)
    {
        return;
    
    free_tree(root->left,free_key,free_value);
    free_tree(root->right,free_key,free_value);
    free_node(root,free_key,free_value);
}

void* BST_get(node* root, void* key,int (*cmp)( void*,  void*))
{
    int comparison = cmp(root->key,key);
    if (root == NULL)
    {
        return NULL;
    }
    if (comparison == 0)
    {
        return root->value;
    }
    if(comparison>0)
    {
        return get(root->right,key,cmp);
    }
    else
    {
        return get(root->left,key,cmp);
    }
}