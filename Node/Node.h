#ifndef _NODE_H_
#define _NODE_H_



typedef struct node {
    void* val;
    node* next;
} node;

node* create_node(void* val, node* next);

void* get_node_val(node* to_get);

node* get_node_next(node* to_get);

void* set_node_val(node* target, void* new_val);

node* set_node_next(node* target, node* new_next);

#endif