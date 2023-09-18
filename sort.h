#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>


/*-PROTOTYPES-*/

/*-GARY-*/
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);

/*-KEVIN-*/
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);

#endif
