#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * print_check - prints section currently being checked
 * @arr: array to search
 * @l: left side
 * @r: right side
 * Return: index of value or -1
 */
void print_check(int *arr, int l, int r)
{
	int i;

	/* Printing current check */
	printf("Searching in array: ");
	for (i = l; i < r; i++)
		printf("%d, ", arr[i]);
	printf("%d\n", arr[r]);
}

/**
 * check_smaller - checks if smaller index with value
 * @arr: array to search
 * @i: index checking
 * @v: value to find
 * @count: number of repeats
 * Return: index of value or -1
 */
int check_smaller(int *arr, int i, int v, int count)
{
	int j = i - 1;

	if (arr[j] && arr[j] == v)
		return (check_smaller(arr, j, v, count + 1));

	if (count > 0)
		print_check(arr, i, i + count);

	return (j + 1);

}

/**
 * real_binary - searches for int in array by dividing in half
 * @arr: array to search
 * @l: left side of array
 * @r: right side of array
 * @v: value to find
 * Return: index of value or -1
 */

int real_binary(int *arr, int l, int r, int v)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		print_check(arr, l, r);

		if (arr[mid] == v)
		{
			if (arr[mid - 1] == v)
			{
				print_check(arr, l, mid);
				return (check_smaller(arr, mid, v, 0));
			}
			return (mid);
		}

		if (arr[mid] > v)
			return (real_binary(arr, l, mid, v));

		return (real_binary(arr, mid + 1, r, v));
	}

	return (-1);
}

/**
 * advanced_binary - searches for int in array by dividing in half
 * @array: array to search
 * @size: size of array
 * @value: value to find
 * Return: index of value or -1
 */

int advanced_binary(int *array, size_t size, int value)
{
	int right = size - 1;

	if (array == NULL)
		return (-1);
	return (real_binary(array, 0, right, value));
}
