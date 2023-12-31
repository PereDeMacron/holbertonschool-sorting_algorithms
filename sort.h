#ifndef SORT_H
#define SORT_H

/*-HEADER FILE-*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

/*-Function print-*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*-PROTOTYPES-*/

/*-GARY-*/
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
/*-Adavanced Tasks-*/
void shell_sort(int *array, size_t size);


/*-KEVIN-*/
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void quicksort(int *array, int min, int max, size_t size);
/*-Adavanced Tasks-*/
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */
