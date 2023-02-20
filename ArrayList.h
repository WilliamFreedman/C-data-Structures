#ifndef _LIST_H_
#define _LIST_H_

#include <stdbool.h>

typedef struct array_list {
	void* elements;
	size_t elem_size;
	size_t num_elements;
} array_list;

/**
 * Creates an array list
 * starts by allocating enough memory for 10 of the specified element
*/

array_list* create_array_list(size_t element_size);

/**
 * Prints each value in the list
 */
void print_list(array_list *list, void (*print_function)(void*));

/**
 * Frees the list
 */
void free_list(array_list *list, void (*free_data)(void *))

#endif
