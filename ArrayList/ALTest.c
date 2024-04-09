#include "ArrayList.h"
#include <stdio.h>

// Define your own data type for testing
typedef struct {
    int data;
} TestData;

// Function to print the data of a TestData pointer
void printTestData(void *dataPtr) {
    TestData *data = (TestData *)dataPtr;
    printf("%d", data->data);
}

void no_op(void* v)
{
    return;
}

int main() {
    int n = 20;
    array_list* list = create_array_list();
    int* arr = (int*)malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
    {
        arr[i] = -i;
        append(list, &arr[i]);
    }

    printf("Elements in the array list: ");
    print_AL(list);

    // Example usage
    add_at(list, &arr[0], 2); // Add 1 at index 2
    printf("After adding 1 at index 2: ");
    print_AL(list);

    list_remove(list, 3); // Remove element at index 3
    printf("After removing element at index 3: ");
    print_AL(list);

    free_list(list, no_op);
    return 0;
}
