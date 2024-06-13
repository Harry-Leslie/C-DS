#ifndef H_ARRAY
#define H_ARRAY
#include <stdlib.h>
#include <stddef.h>
/* 
    Array Requirements

    fixed size in memory whether that be on the stack or heap
    contain the same datatype in our case
    allows

    reading and writing of elements within the array via indexes
    creating and freeing arrays
*/

struct Array
{
    size_t size;
    size_t bytes;
    void* array; 
};

typedef struct Array Array;
Array create_array(size_t size, size_t bytes);
void* read_array(Array a, size_t index);
void write_array(Array* a, size_t index, void* data);
void free_array(Array* a);

#endif