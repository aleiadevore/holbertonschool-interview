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
	int row_size;

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
	sponge = malloc(sizeof(char *) * row_size * row_size);
	if (!sponge)
		return;
	printf("Row size: %d\n", row_size);
	make_menger(level, 1, sponge);
	printf("row_size: %d\n", row_size);
	print_menger(sponge, row_size);
	free(sponge);

	/* WOULD IT BE BETTER TO FILL IN ALL WITH # AND THEN REPLACE WITH SPACE? */
}

void make_menger(int level, int place, char **sponge)
{
	int i, j, subsize;
	char **sub_array = NULL;

	/* First level logic only */
	subsize = pow(3, place);
	printf("Subsize: %d\n", subsize);
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
	printf("Make malloc works\n");
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
		sponge = sub_array;
		for (i = 0; i < subsize; i++)
		{
			for (j = 0; j < subsize; j++)
				printf("%c", sponge[i][j]);
			printf("\n");
		}
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

	printf("In print\nTesttest\n");
	fflush(stdout);
	printf("Test");
	printf("row_size: %d", row_size);
	for (i = 0; i < row_size; i++)
	{
		printf("i: %d", i);
		for (j = 0; j < row_size; j++)
		{
			printf("j: %d", j);
			putchar(sponge[i][j]);
		}
		printf("\n");
	}
}
