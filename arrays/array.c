#include "array.h"

Array create_array(size_t size, size_t bytes)
{
    Array new_array;
    new_array.size = size;
    new_array.bytes = bytes;
    new_array.array = malloc(sizeof(char)*bytes*size);
    return new_array;
}

void *read_array(Array a, size_t index)
{
    return (char*)(a.array)+(index*a.bytes);
}

void write_array(Array* a, size_t index, void* data)
{
    char* start = ((char*)(a->array)+(index*a->bytes));
    for (int i = 0; i < a->bytes; i++){
        start[i] = ((char*)data)[i];
    }
}

void free_array(Array* a)
{
    free(a->array);
    a->array=NULL;
}   

