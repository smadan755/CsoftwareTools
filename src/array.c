#include "array.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void init_array(int capacity, size_t element_size ,Array* array) {
    array->capacity = capacity;
    array->length = 0;
    array->construct_array = construct_array;
//    array->print_array = print_array;
    array->push_back = push_back;
    array->element_size = element_size;
    array->free_array = free_array;
    array->pop_back = pop_back;
    construct_array(array);
}
void construct_array(Array* array) {
    array->data = (int*)malloc(array->capacity * array->element_size);
}
void push_back(void* element, Array* array) {
    if (array->length == array->capacity) {
        // Double the capacity and reallocate memory
        array->capacity *= 2;
        array->data = realloc(array->data, array->capacity * array->element_size);
        if (array->data == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    // Copy the element into the array
    void* target = (char*)array->data + (array->length * array->element_size);
    memcpy(target, element, array->element_size);
    array->length++;
}
void free_array(Array* array) {
    free(array->data);
}
void pop_back(Array* array) {
    array->length--;
}
//
//void print_array(Array* array) {
//    for (int i = 0; i < array->length; i++) {
//        if (i == 0) {
//            if (array->length == 1) {
//                printf("[ %d ]",array->data[i]);
//            } else {
//                printf("[ %d",array->data[i]);
//            }
//        } else if (i == array->length - 1) {
//            printf( " %d ]",array->data[i]);
//        } else {
//            printf(" %d",array->data[i]);
//        }
//    }
//}