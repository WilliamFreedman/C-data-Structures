#include "node.h"
#include <stdlib.h>

node* create_node(void* val, node* next)
{
    node* n = (node*)malloc(sizeof(node));
    if (n == NULL)
    {
        return NULL;
    }
    n->val = val;
    n->next = next;
    return n;
}

void* get_node_val(node* to_get)
{
    return to_get->val;
}

node* get_node_next(node* to_get)
{
    return to_get->next;
}

void* set_node_val(node* target, void* new_val)
{
    target->val = new_val;
}

node* set_node_next(node* target, node* new_next)
{
    target->next = new_next;
}