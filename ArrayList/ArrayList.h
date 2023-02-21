#ifndef _LIST_H_
#define _LIST_H_

#include <stdbool.h>

typedef struct array_list {
	void** elements; //pointer to the elements stored by the array list
	size_t elem_size; //the size of the elements stored by the list
	size_t num_elements; //number of elements actually stored
	size_t allocated_size; //max number of elements that can be stored without reallocating
} array_list;

/**
 * Creates an array list
 * starts by allocating enough memory for 10 of the specified element
*/

array_list* create_array_list();

array_list* reallocate(array_list* list);

/**
 * Adds an element to the selected index
 */

bool add(array_list *list, void* data, int idx);

/**
 * Prints each value in the list
 */
void print_list(array_list *list, void (*print_function)(void*));

/**
 * Frees the list
 */
void free_list(array_list *list, void (*free_data)(void *));

#endif
