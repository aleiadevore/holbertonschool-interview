#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void merge(int *array, int l, int m, int r);
void sort(int *array, int l, int r);

#endif /* SORT_H */
