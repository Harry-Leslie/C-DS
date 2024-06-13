#include "darray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


vector create_vector(size_t initial_size, size_t bytes){
    vector vect;
    vect.bytes=bytes;
    vect.size=initial_size;
    vect.current=0;
    vect.arr=malloc(sizeof(char)*initial_size*bytes);
    if (vect.arr==NULL){
        printf("Warning: malloc failed due to being unable to find a memory location please");
        exit(1);
    }
    return vect;
}


void push_back(vector* vect, void* item){
    if (vect->current >= vect->size){
        vect->arr=realloc(vect->arr, (vect->size*vect->bytes)*2+1);
        if (vect->arr == NULL){
            printf("Warning: realloc failed");
            return NULL;
        }
        vect->size=vect->size*2+1;
    }

    char* start = ((char*)vect->arr)+(vect->current*vect->bytes);

    memcpy(start, item, vect->bytes);
    vect->current++;

}

int empty_array(vector vect){
    return (vect.current==0);
}

void resize(vector* vect, size_t n){
    vect->arr= realloc(vect->arr, vect->bytes*n);
    if (vect->arr == NULL){
        printf("Warning: realloc failed due to being unable to find a memory location please");
        exit(1);

    }
}

void* pop_back(vector* vect){
    if (!empty_array(*(vect))){
        int temp = --vect->current;
        return (char*)vect->arr+(temp*vect->bytes);
        
    }
    return NULL;
}

void insert(vector* vect, void* item, size_t index){
    if (index >= vect->size){
        vect->arr=realloc(vect->arr, (index*2+1)*vect->bytes);
        vect->size=index*2+1;
    }
    if (vect->arr==NULL){
        printf("\nWarning: malloc failed due to being unable to find a memory location please");
        exit(1);
    }
    if (index >= vect->current){
        vect->current=index+1;
    }
    char* start = ((char*)vect->arr)+((index)*vect->bytes);

    memcpy(start, item, vect->bytes);

}

void* find(vector vect, size_t index){
    if (index >= vect.size){
        printf("Warning: out of range");
        return NULL;
    }

    if (index >= vect.current){
        vect.current=index;
    }
    return ((char*)vect.arr)+(index*vect.bytes);

}