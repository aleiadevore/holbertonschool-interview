#include "sort.h"

/* Size of left should be larger than size of right */
/* Sort left before sorting right */

/*
 * Algorithm: Recursively divide halves until size of array == 1
 * then start merging back together until array complete
*/

/**
 * print_done - prints sorted section
 * @array: array being sorted
 * @n: starting index
 * @k: ending index
 * Return: NULL
 */

void print_done(int *array, int n, int k)
{
	printf("[Done]: ");
	for (; n < k; n++)
	{
		if (n == k - 1)
			printf("%d\n", array[n]);
		else
			printf("%d, ", array[n]);
	}
}

/**
 * merge_sort - sorts array of int using merge sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	if (!array || size < 1)
		return;
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
	int L[1024], R[1024];

	for (i = 0; i < n1; i++)
	{
		L[i] = array[l + i];
		if (i != n1 - 1)
			printf("%d, ", L[i]);
		else
			printf("%d", L[i]);
	}
	printf("\n[right]: ");
	for (j = 0; j < n2; j++)
	{
		R[j] = array[m + 1 + j];
		if (j != n2 - 1)
			printf("%d, ", R[j]);
		else
			printf("%d\n", R[j]);
	}
	for (k = l, i = 0, j = 0; i < n1 && j < n2; k++)
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
	for (; i < n1; i++, k++)
		array[k] = L[i];
	for (; j < n2; j++, k++)
		array[k] = R[j];
	print_done(array, l, k);
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
	int m;

	if (l < r)
	{
		m = (l + r - 1) / 2;
		sort(array, l, m);
		sort(array, m + 1, r);
		printf("Merging...\n");
		printf("[left]: ");
		merge(array, l, m, r);
	}
}
