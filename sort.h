#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdarg.h>
#include <limits.h>
#include <float.h>
#include <assert.h>
#include <errno.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int lb, int ub, size_t size);
void merge_sort(int *array, size_t size);
void merge_helper(int array[], int lb, int ub);
void print_merge_done(const int *array, int lb, int ub);
void print_merge_step(const int *array, int lb, int mid, int ub);
void merge(int array[], int lb, int mid, int ub);
void cpy(int array[], int arr[], int lb, int ub);


#endif
