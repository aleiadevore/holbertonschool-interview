#include "menger.h"

/**
 * menger - prints menger sponge or nothing if level < 0
 * @level: level of sponge to print
 *
 * Return: none
 */

void menger(int level)
{
	char **sponge = NULL;
	int row_size, i;

	/* Special cases */
	if (level < 0)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}

	/* Malloc 3^level * 3^level matrix */
	row_size = pow(3, level);
	sponge = make_sub(sponge, row_size);

	make_menger(level, 1, sponge);
	print_menger(sponge, row_size);
	for (i = 0; i < row_size; i++)
		free(sponge[i]);
	free(sponge);

	/* WOULD IT BE BETTER TO FILL IN ALL WITH # AND THEN REPLACE WITH SPACE? */
}

/**
 * make_menger - makes one menger level
 * @level: level of menger
 * @place: number of levels created
 * @sponge: final menger sponge
 *
 * Return: void
 */

void make_menger(int level, int place, char **sponge)
{
	int i, j, subsize;
	char **sub_array = NULL;

	/* First level logic only */
	subsize = pow(3, place);
	sub_array = make_sub(sub_array, subsize);
	for (i = 0; i < subsize; i++)
	{
		for (j = 0; j < subsize; j++)
		{
			if (j == 1 && i == 1)
				sub_array[i][j] = ' ';
			else
				sub_array[i][j] = '#';
		}
	}

	if (level == place)
	{
		for (i = 0; i < subsize; i++)
		{
			for (j = 0; j < subsize; j++)
				sponge[i][j] = sub_array[i][j];
		}
		for (i = 0; i < subsize; i++)
			free(sub_array[i]);
		free(sub_array);
	}
}

/**
 * print_menger - prints menger sponge
 * @sponge: sponge to print
 * @row_size: size of one row
 *
 * Return: void
 */

void print_menger(char **sponge, int row_size)
{
	int i, j;

	for (i = 0; i < row_size; i++)
	{
		for (j = 0; j < row_size; j++)
			putchar(sponge[i][j]);
		printf("\n");
	}
}

/**
 * make_sub - mallocs matrix
 * @sub_array: matrix to make
 * @subsize: size of matrix
 *
 * Return: matrix or NULL on error
 */

char **make_sub(char **sub_array, int subsize)
{
	int i;

	sub_array = malloc(sizeof(char *) * subsize);
	if (!sub_array)
		return (NULL);
	for (i = 0; i < subsize; i++)
	{
		sub_array[i] = malloc(sizeof(char) * subsize);
		if (!sub_array[i])
		{
			free(sub_array);
			return (NULL);
		}
	}
	return (sub_array);
}
