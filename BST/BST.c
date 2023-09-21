#include <stdlib.h>
#include "BST.h"
#include <stdio.h>

BST* create_BST(int (*comp)(void*,void*))
{
    BST* bst = (BST*)malloc(sizeof(BST));

    if (bst == NULL)
    {
        return NULL;
    }
    else
    {
        bst->key_cmp = comp;
        bst->root = NULL;
        bst->num_nodes = 0;
        return bst;
    }
}

int isEmpty(BST* tree)
{
    return tree->num_nodes == 0;
}

void free_2(node*n)
{
    free(n);
}
void free_BST(BST* tree)
{
    postorder(tree,free_2);
}


static void* root_remove(node* root, void* key_val, int (*key_comp)(void*,void*))
{
    if (root == NULL)
    {
        return NULL;
    }

    int comp_result = key_comp(key_val,root->value);

    if (comp_result < 0)
    {
        root->left = root_remove(root->left, key_val,key_comp);
        return root;
    } 

    else if (comp_result > 0)
    {
        root->right = root_remove(root->right, key_val,key_comp);
        return root;
    }

    if (root->left == NULL)
    {
        node* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL)
    {
        node* temp = root->left;
        free(root);
        return temp;
    }
    else
    {
        node* next_parent = root;

        node* next = root->right;

        while (next->left != NULL) {
            next_parent = next;
            next = next->left;
        }

        if (next_parent != root)
            next_parent->left = next->right;
        else
            next_parent->right = next->right;
 
        root->key = next->key;

        free(next);

        return root;
    }
}

void* tree_remove(BST* tree, void* key_val)
{
    void* r = root_remove(tree->root,key_val,tree->key_cmp);
    if (r != NULL)
    {
        tree->num_nodes--;
    }
    return r;
}

static void root_inorder(node* root, void (*toRun)(node*))
{
    if (root == NULL)
    {
        return;
    }
    root_inorder(root->left,toRun);
    toRun(root);
    root_inorder(root->right,toRun);
}

static void root_preorder(node* root, void (*toRun)(node*))
{
    if (root == NULL)
    {
        return;
    }
    toRun(root);
    root_preorder(root->left,toRun);
    root_preorder(root->right,toRun);
}

static void root_postorder(node* root, void (*toRun)(node*))
{
    if (root == NULL)
    {
        return;
    }
    root_postorder(root->left,toRun);
    root_postorder(root->right,toRun);
    toRun(root);
}

void inorder(BST* tree, void (*toRun)(node*))
{
    root_inorder(tree->root,toRun);
    printf("\n");
}

void preorder(BST* tree, void (*toRun)(node*))
{
    root_preorder(tree->root,toRun);
}

void postorder(BST* tree, void (*toRun)(node*))
{
    root_postorder(tree->root,toRun);
}

int contains(BST* tree, void* key_val)
{
    node* root = tree->root;

    while (1)
    {
        if (root == NULL)
        {
            return 0;
        }

        int comp_result = tree->key_cmp(key_val,root->value);

        if (comp_result == 0)
        {
            return 1;
        }

        if (comp_result>0)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
}

void* find(BST* tree, void* key_val)
{
    node* root = tree->root;

    while (1)
    {
        if (root == NULL)
        {
            return NULL;
        }

        int comp_result = tree->key_cmp(key_val,root->value);

        if (comp_result == 0)
        {
            return root->value;
        }

        if (comp_result>0)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
}

void* add(BST* tree, void* key_val, void* val)
{
    node* n = create_node(key_val,val);

    if (n == NULL)
    {
        return NULL;
    }
    if (tree->num_nodes == 0)
    {
        tree->root = n;
        tree->num_nodes++;
        return val;
    }
    else
    {
        node* root = tree->root;
        while (1)
        {   
            if (root == NULL)
            {
                printf("null root in add, mistake");
            }
            //positive if key>root, negative if key<root
            int comp_result = tree->key_cmp(key_val,root->value);
            if (comp_result >= 0)
            {
                if (root->right == NULL)
                {
                    root->right = n;
                    tree->num_nodes++;
                    return val;
                }
                else
                {
                    root = root->right;
                }
            }
            else
            {
               if (root->left == NULL)
                {
                    root->left = n;
                    return val;
                }
                else
                {
                    root = root->left;
                } 
            }
        }
    }
}

int node_depth(node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int r1 = node_depth(root->right)+1;
    int r2 = node_depth(root->left)+1;
    if (r1>=r2)
    {
        return r1;
    }
    else
    {
        return r2;
    }
}

int depth(BST* tree)
{
    return node_depth(tree->root);
}
