#ifndef _LIST_H_
#define _LIST_H_

#include <stdbool.h>
#include <stdlib.h>

typedef struct array_list {
	void** elements; //pointer to the elements stored by the array list
	size_t num_elements; //number of elements actually stored
	size_t allocated_size; //max number of elements that can be stored without reallocating
} array_list;

/**
 * Creates an array list
 * starts by allocating enough memory for 10 of the specified element
*/
array_list* create_array_list();

/**
 * Changes the internal memory allocated for the elements
 * To be called when adding an element to a full list
 */ 
void** reallocate(array_list* list);

/**
 * Adds an element to the selected index
 */

void* A_L_add(array_list *list, void* data, int idx);

/**
 * Prints each value in the list
 */
void print_list(array_list *list, void (*print_function)(void*));

/**
 * Frees the list
 */
void free_list(array_list *list, void (*free_data)(void *));

/**
 * Returns the element from a given index
 */ 
void* A_L_get(array_list *list, int idx);

/**
 * Removes an element from a given index in the list and frees that element
 */ 
void* A_L_remove(array_list *list, int idx, void (*free_data)(void *));

#endif
