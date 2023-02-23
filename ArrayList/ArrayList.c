#include <stdlib.h>
#include <stdio.h>
#include "ArrayList.h"

array_list* create_array_list()
{
	array_list* list = malloc(sizeof(array_list));
	list->elements = (void**)malloc(10);
	//*(char*)(list->elements + 10) = NULL;
	list->num_elements = 0;
	list->allocated_size = 10;
	return list;
}

void blank (void* a){}

void* add(array_list *list, void* data, int idx)
{
	if (idx > list->num_elements)
	{
		fprintf(stderr, "Index out of bounds error: Atempt to add to position %d with array size %i",idx,list->num_elements);
		free_list(list,blank);
		exit(1);
	}
	
	if (list->num_elements + 1 >= list->allocated_size)
	{
		reallocate(list);
	}

	void** last = list->elements + list->num_elements - 1;
	for (int i = list->num_elements; i>idx;i++)
	{
		*(last + 1) = *last--;
	}
	*(list->elements + idx) = data;
	return data;
}

void* remove(array_list *list, int idx, void (*free_data)(void *))
{
	void** ptr = list->elements + idx;
	void* toReturn = *ptr;
	if (idx == list->num_elements -1)
	{
		free(*ptr);
		return toReturn;
	}
	
	*ptr = NULL;
	for (int i=idx+1;i<list->num_elements - 1;i++)
	{
		*(ptr-1) = *ptr++;
	}
	return toReturn;
}

void** reallocate(array_list* list)
{
	size_t new_size = (list->allocated_size)*2 + 1;
	void** new_elements = (void**)malloc(new_size*sizeof(void**));
	void** new_holder = new_elements;
	void** old_holder = list->elements;
	for (int i=0;i<list->num_elements;i++)
	{
		*new_elements = *(list->elements);
		new_elements++;
		list->elements++;
	}
	free(old_holder);
	list->elements = new_holder;
	list->allocated_size = new_size;
	return list->elements;
}

void* get(array_list *list, int idx)
{
	return *(list->elements + idx);
}

void free_list(array_list *list, void (*free_data)(void *))
{
	for(int i=0;i<list->num_elements;i++)
	{
		free_data(list->elements + i);
	}
	free(list);
}

void print_list(array_list* list, void (*print_function)(void*))
{
	printf("[");
	for(int i=0;i<list->num_elements;i++)
	{
		print_function(list->elements + i);
		if(i != list->num_elements - 1)
		{
			printf(", ");
		}
	}
	printf("]");
}
