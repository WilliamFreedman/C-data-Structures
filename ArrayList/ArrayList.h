#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#include <stdlib.h>

typedef struct array_list {
	void** elements; //pointer to the elements stored by the array list
	int num_elements; //number of elements actually stored
	int allocated_size; //max number of elements that can be stored without reallocating
} array_list;

/**
 * Creates an array list
 * starts by allocating enough memory for 10 null pointers
 * returns NULL if malloc failed
*/
array_list* create_array_list();

/**
 * Adds an element to the end of the ArrayList
 */ 
void append(array_list* list, void* to_add);

/**
 * sets the value of list[idx] to to_add. Returns 1 if this was successful, 0 if it failed.
 */ 
int set(array_list* list, void* to_add, int idx);

/**
 * Returns a pointer to the start of the object at idx
 * This should be casted and dereferneced immediatly, if array_list needs to reallocate its memory, the pointer will be useless
 */ 
void* get(array_list* list, int idx);

int add_at(array_list* list, void* to_add, int idx);

int list_remove(array_list* list, int idx);

void run_on_all(array_list* list, void (*to_run)(void *));

void free_list(array_list* list, void (*free_elem)(void *));

void print_AL(array_list* list);

#endif
