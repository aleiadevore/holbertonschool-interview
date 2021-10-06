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
	sponge = malloc(sizeof(char *) * row_size);
	if (!sponge)
		return;
	for (i = 0; i < row_size; i++)
	{
		sponge[i] = malloc(sizeof(char) * row_size);
		if (!sponge[i])
		{
			free(sponge);
			return;
		}
	}
	make_menger(level, 1, sponge);
	print_menger(sponge, row_size);
	for (i = 0; i < row_size; i++)
		free(sponge[i]);
	free(sponge);

	/* WOULD IT BE BETTER TO FILL IN ALL WITH # AND THEN REPLACE WITH SPACE? */
}

void make_menger(int level, int place, char **sponge)
{
	int i, j, subsize;
	char **sub_array = NULL;

	/* First level logic only */
	subsize = pow(3, place);
	sub_array = malloc(sizeof(char*) * subsize);
	if (!sub_array)
		return;
	for (i = 0; i < subsize; i++)
	{
		sub_array[i] = malloc(sizeof(char) * subsize);
		if (!sub_array[i])
		{
			free(sub_array);
			return;
		}
	}
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
		return;
	}

	

	/* Next level logic */
	/*subsize = pow(3, place);
	sub_array = malloc(sizeof(char) * subsize * subsize);
	for (i = 0; i < subsize; i++)
	{
		for (j = 0; j < subsize; j++)
	}

	free(sub_array);*/
	return;
	
}

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
