#include "sandpiles.h"

/**
 * sandpiles_sum - computes a stable sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 * Return: void
*/


void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int temp[3][3];
	int i, j, bool = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			temp[i][j] = grid1[i][j];
			grid1[i][j] = temp[i][j] + grid2[i][j];
			if (grid1[i][j] >= 4)
				bool = 1;
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			temp[i][j] = grid1[i][j];
		}
	}
    /* If unstable, print sandpile before toppling */
	if (bool == 1)
	{
		print_grid1(grid1);
		topple_grid(grid1, temp);
	}
}

/**
 * print_grid1 - prints grid 1
 * @grid1: grid1
 *
 * Return: void
 */

void print_grid1(int grid1[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j < 2)
				printf("%d ", grid1[i][j]);
			else
				printf("%d", grid1[i][j]);
		}
		printf("\n");
	}
}

/**
 * topple_grid - topples the grid
 * @grid1: grid to topple
 * @temp: previous state of grid1
 *
 * Return: void
 */

void topple_grid(int grid1[3][3], int temp[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (temp[i][j] > 3)
				add_around(grid1, i, j);
		}
	}
	check_grid(grid1, temp);
}

/**
 * check_grid - checks if grid is stable
 * @grid1: grid to check
 * @temp: previous state of grid1
 *
 * Return: void
 */

void check_grid(int grid1[3][3], int temp[3][3])
{
	int i, j, bool = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] >= 4)
				bool = 1;
		}
	}
	if (bool == 1)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
				temp[i][j] = grid1[i][j];
		}
		print_grid1(grid1);
		topple_grid(grid1, temp);
	}
}
/**
 * add_around - adds around position
 * @g: grid to manipulate
 * @i: row in grid
 * @j: column in grid
 * Return: void
 */

void add_around(int g[3][3], int i, int j)
{
	if (i > 0)
		g[i - 1][j] += 1;
	if (i < 2)
		g[i + 1][j] += 1;
	if (j > 0)
		g[i][j - 1] += 1;
	if (j < 2)
		g[i][j + 1] += 1;
	g[i][j] -= 4;
}
