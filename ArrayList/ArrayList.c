#include "ArrayList.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

array_list* create_array_list()
{
	array_list* list = (array_list*)malloc(sizeof(array_list));

	if (list == NULL)
	{
		return NULL;
	}

	list->elements = malloc(10*sizeof(void*));

	if (list->elements == NULL)
	{
		return NULL;
	}

	list->num_elements = 0;

	list->allocated_size = 10;

	return list;
}

int reallocate(array_list* list)
{
	int sz = (list->allocated_size*2)+1;
	void** new = (void**)malloc(sz);

	for (int i=0;i<list->num_elements;i++)
	{
		*(new+i) = *(list->elements + i);
	}

	free(list->elements);

	list->elements = new;

	return 1;
}

void append(array_list* list, void* to_add)
{
	if (list->num_elements == list->allocated_size)
	{
		reallocate(list);
	}

	*((list->elements) + list->num_elements) = to_add;
	list->num_elements++;
}

int set(array_list* list, void* to_add, int idx)
{
	if (idx >= list->num_elements || idx<0) //indexOutOfBounds exception
	{
		return 0;
	}

	*(list->elements + idx) = to_add;

	return 1;
}

void* get(array_list* list, int idx)
{
	return *(list->elements + idx);
}

//idx is the index you're adding to
static void shift_right(array_list* list, int idx)
{
	int i = list->num_elements-1;

	while (i>=idx)
	{
		*(list->elements + i + 1) = *(list->elements + i);
		i--;
	}
}

int add_at(array_list* list, void* to_add, int idx)
{
	if (list->num_elements == list->allocated_size)
	{
		reallocate(list);
	}

	if (list->elements == NULL)
	{
		return 0;
	}

	list->num_elements++;

	shift_right(list,idx);

	set(list,to_add,idx);

	return 1;
}
//idx is the index you're adding to
static void shift_left(array_list* list, int idx)
{
	int i = idx;

	while (i<list->num_elements)
	{
		*(list->elements + i) = *(list->elements + i+1);
		i++;
	}
}
int list_remove(array_list* list, int idx)
{

	if (idx<0)
	{
		idx = list->num_elements + idx;
	}

	if (idx >= list->num_elements || idx<0) //indexOutOfBounds exception
	{
		return 0;
	}

	shift_left(list,idx);

	list->num_elements--;
	return 1;
}

void free_list(array_list* list, void (*free_key)(void *))
{
	for(int i=0;i<list->num_elements;i++)
	{
		free(*(list->elements + i));
	}
	free(list->elements);
	free(list);
}

void run_on_all(array_list* list, void (*to_run)(void *))
{
	for(int i=0;i<list->num_elements;i++)
	{
		to_run(*(list->elements + i));
	}
}
