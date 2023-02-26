#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vec_init(struct vector_t *vec, int capacity) {
	vec->size = 0;
	vec->capacity = capacity;
	vec->arr = malloc(vec->capacity * sizeof(int));
}

void vec_resize(struct vector_t *vec, int capacity) {
	vec->capacity = capacity;
	vec->arr = realloc(vec->arr, vec->capacity * sizeof(int));
}

void vec_push(struct vector_t *vec, int element) {
	if(vec->size == vec->capacity) {
		vec_resize(vec, vec->capacity * 2);
	}

	vec->arr[vec->size] = element;
	vec->size++;
}

void vec_pop(struct vector_t *vec) {
	if(vec->size > 0) {
		vec->size--;
	}
}

void vec_clear(struct vector_t *vec) {
	vec->size = 0;
}

bool vec_empty(struct vector_t *vec) {
	if(vec->size == 0) {
		return true;
	}

	return false;
}

void vec_push_all(struct vector_t *vec, int arr[], int size) {
	while(vec->capacity - vec->size < size) {
		vec_resize(vec, vec->capacity * 2);
	}

	for(int i = 0; i < size; i++, vec->size++) {
		vec->arr[vec->size] = arr[i];
	}
}

void vec_erase(struct vector_t *vec, int index) {
	for(int i = index; i < vec->size - 1; i++) {
		vec->arr[i] = vec->arr[i + 1];
	}

	vec->size--;
}

void vec_erase_all(struct vector_t *vec, int start, int end) {
	for(int i = start, j = end; j < vec->size - 1; i++, j++) {
		vec->arr[i] = vec->arr[j + 1];
	}

	vec->size -= end - start + 1;
}

void vec_stf(struct vector_t *vec) {
	vec_resize(vec, vec->size);
}

void vec_print(struct vector_t *vec) {
	for(int i = 0; i < vec->size; i++) {
		printf("%d ", vec->arr[i]);
	}

	printf("\n");
}

void vec_destroy(struct vector_t *vec) {
	vec->size = 0;
	vec->capacity = 0;
	
	free(vec->arr);
}
