#ifndef H_DARRAY
#define H_DARRAY
#include <stdlib.h>

struct Vector
{
    size_t size;
    size_t bytes;
    void* arr;
    size_t current; // current size being used up
};

typedef struct Vector vector;

vector create_vector(size_t initial_size, size_t bytes);
void push_back(vector* vect, void* item);
void insert(vector* vect, void* item, size_t index);
void* find(vector vect, size_t index);
void resize(vector* vect, size_t n);
int empty_array(vector vect);
void* pop_back(vector* vect);



#endif