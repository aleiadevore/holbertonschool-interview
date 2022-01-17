#include "sort.h"

/* Size of left should be larger than size of right */
/* Sort left before sorting right */

/*
 * Algorithm: Recursively divide halves until size of array == 1
 * then start merging back together until array complete
*/

/**
 * merge_sort - sorts array of int using merge sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	sort(array, 0, size - 1);
}

/**
 * merge - merges sorted arrays together
 * @array: array to merge
 * @l: left side
 * @m: middle
 * @r: right side
 * Return: void
 */
void merge(int *array, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];

	printf("Merging...\n");
	printf("[left]: %d\n[right]: %d\n", array[l], array[r]);
	for (i = 0; i < n1; i++)
		L[i] = array[l + i];
	for (j = 0; j < n2; j++)
		R[j] = array[m + 1 + j];

	k = l;
	for (i = 0, j = 0; i < n1 && j < n2; k++)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
	}
	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}
}

/**
 * sort - driving recursive function
 * @array: array to merge
 * @l: left side
 * @r: right side
 * Return: void
 */
void sort(int *array, int l, int r)
{
	int m, i;

	if (l < r)
	{
		m = (l + r) / 2;
		sort(array, l, m);
		sort(array, m + 1, r);
		merge(array, l, m, r);
		printf("[Done]: ");
		for (i = 0; i <= r; i++)
			printf("%d, ", array[i]);
		printf("\n");
	}
}
