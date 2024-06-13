#include "darray.h"
#include <stdio.h>
#include <string.h>

void print_vector(vector vect);

int main() {
    // Create a vector to hold integers
    vector vect = create_vector(10, sizeof(int));

    // Push back some integers
    for (int i = 1; i <= 5; i++) {
        push_back(&vect, &i);
    }
    print_vector(vect);

    // Insert an element at index 2
    int item = 99;
    insert(&vect, &item, 2);
    print_vector(vect);

    // Find an element at index 2
    int* found_item = (int*)find(vect, 2);
    if (found_item != NULL) {
        printf("Item found at index 2: %d\n", *found_item);
    } else {
        printf("Item not found at index 2\n");
    }

    // Pop back an element
    int* popped_item = (int*)pop_back(&vect);
    if (popped_item != NULL) {
        printf("Item popped: %d\n", *popped_item);
    } else {
        printf("Pop failed, array is empty\n");
    }
    
    int a = 12;
    int b = 10;

    insert(&vect, &a, 12);
    insert(&vect, &b, 4);

    print_vector(vect);

    // Check if the vector is empty
    if (empty_array(vect)) {
        printf("The vector is empty\n");
    } else {
        printf("The vector is not empty\n");
    }


    // Clean up
    free(vect.arr);

    return 0;
}

void print_vector(vector vect) {
    printf("Vector contents: ");
    for (size_t i = 0; i < vect.current; i++) {
        int* item = (int*)((char*)vect.arr + i * vect.bytes);
        printf("%d ", *item);
    }
    printf("\n");
}
