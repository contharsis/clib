#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>

struct vector_t {
        int size;
        int capacity;
        int *arr;
};

void vec_init(struct vector_t *vec, int capacity);

void vec_resize(struct vector_t *vec, int capacity);

void vec_push(struct vector_t *vec, int element);

void vec_pop(struct vector_t *vec);

void vec_clear(struct vector_t *vec);

bool vec_empty(struct vector_t *vec);

void vec_push_all(struct vector_t *vec, int arr[], int size);

void vec_erase(struct vector_t *vec, int index);

void vec_erase_all(struct vector_t *vec, int start, int end);

void vec_stf(struct vector_t *vec);

void vec_print(struct vector_t *vec);

void vec_destroy(struct vector_t *vec);

#endif
