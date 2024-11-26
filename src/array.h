//
// Created by madan on 11/24/2024.
//

#ifndef CSOFTWARETOOLS_ARRAY_H
#define CSOFTWARETOOLS_ARRAY_H

#include <stddef.h> // For size_t


typedef struct Array{
    int capacity;
    int length;

    size_t element_size;

    int* data;

    void (*construct_array)(struct Array*);
//    void (*print_array)(struct Array*);
    void (*push_back)(void*, struct Array*);

    void (*free_array)(struct Array*);

    void (*pop_back)(struct Array*);


} Array;

void init_array(int capacity, size_t element_size ,Array* array);

void construct_array(Array* array);

//void print_array(Array* array);
void push_back(void* element, Array* array);

void free_array(Array* array);

void pop_back(Array* array);


#endif //CSOFTWARETOOLS_ARRAY_H


