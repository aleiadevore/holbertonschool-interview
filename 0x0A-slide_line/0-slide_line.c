#include "slide_line.h"
/**
 * slide_line - slides numbers in array left or right. Ident. numbers merged
 *
 * @line: single array with ints to slide
 * @size: number of elements
 * @direction: direction to move ints
 * Return: 1 on success, 0 on fail
 */

int slide_line(int *line, size_t size, int direction)
{
	int s = size;

	if (direction == SLIDE_LEFT)
		return (slide_left(line, s));
	else if (direction == SLIDE_RIGHT)
		return (slide_right(line, s));
	else
		return (0);
}

/**
 * slide_left - slides line left
 *
 * @line: line to slide
 * @size: size of array
 * Return: 1 on success 0 on failure
 */

int slide_left(int *line, int size)
{
	int prev = 0, i, dup_count = 0, dupI = 0;
	int dup[2048];

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (line[i] == prev && dup_count == 1)
			{
				dup[dupI] = prev * 2;
				dupI++;
				prev = 0;
				dup_count = 0;
			}
			else if (line[i] != prev && prev != 0)
			{
				dup[dupI] = prev;
				dupI++;
				prev = line[i];
				dup_count = 1;
			}
			else
			{
				dup_count++;
				prev = line[i];
			}
		}
	}
	if (dup_count != 0)
	{
		dup[dupI] = prev;
		dupI++;
	}
	/* Filling in rest of dup */
	for (; dupI < size; dupI++)
		dup[dupI] = 0;

	for (i = 0; i < size; i++)
		line[i] = dup[i];
	return (1);
}

/**
 * slide_right - slides line right
 *
 * @line: line to slide
 * @size: size of array
 *
 * Return: 1 on success 0 on failure
 */

int slide_right(int *line, int size)
{
	int prev = 0, i, dup_count = 0, dupI = size - 1;
	int dup[2048];

	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if (line[i] == prev && dup_count == 1)
			{
				dup[dupI] = prev * 2;
				dupI--;
				prev = 0;
				dup_count = 0;
			}
			else if (line[i] != prev && prev != 0)
			{
				dup[dupI] = prev;
				dupI--;
				prev = line[i];
				dup_count = 1;
			}
			else
			{
				dup_count++;
				prev = line[i];
			}
		}
	}
	if (dup_count != 0)
	{
		dup[dupI] = prev;
		dupI--;
	}
	/* Filling in rest of dup */
	for (; dupI >= 0; dupI--)
		dup[dupI] = 0;

	for (i = 0; i < size; i++)
		line[i] = dup[i];
	return (1);
}
