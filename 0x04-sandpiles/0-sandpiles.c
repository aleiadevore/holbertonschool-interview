#include "sandpiles.h"

/**
 * sandpiles_sum - computes a stable sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 * Return: void
*/


void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int tmp[3][3];
	int i, j, bool = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			tmp[i][j] = grid1[i][j];
			grid1[i][j] = tmp[i][j] + grid2[i][j];
			if (grid1[i][j] >= 4)
				bool = 1;
		}
	}

    /* If unstable, print sandpile before toppling */
	if (bool == 1)
	{
		print_grid1(grid1);
		topple_grid(grid1);
	}
}

/**
 * prind_grid1 - prints grid 1
 * @grid1 - grid1
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
			if (j <= 2)
				printf("%d ", grid1[i][j]);
			else
				printf("%d", grid1[i][j]);
		}
		printf("\n");
	}
}

void topple_grid(int grid1[3][3])
{
	int i, j, bool = 0;

	if (grid1[1][1] > 3)
	{
		add_around(grid1, 1, 1);
		grid1[1][1] -= 4;
	}
	if (grid1[0][1] > 3)
	{
		add_around(grid1, 0, 1);
		grid1[0][1] -= 4;
	}
	if (grid1[1][0] > 3)
	{
		add_around(grid1, 1, 0);
		grid1[1][0] -= 4;
	}
	if (grid1[1][2] > 3)
	{
		add_around(grid1, 1, 2);
		grid1[1][2] -= 4;
	}
	if (grid1[2][1] > 3)
	{
		add_around(grid1, 2, 1);
		grid1[2][1] -= 4;
	}
	if (grid1[0][0] > 3)
	{
		add_around(grid1, 0, 0);
		grid1[0][0] -= 4;
	}
	if (grid1[0][2] > 3)
	{
		add_around(grid1, 0, 2);
		grid1[0][2] -= 4;
	}
	if (grid1[2][0] > 3)
	{
		add_around(grid1, 2, 0);
		grid1[2][0] -= 4;
	}
	if (grid1[2][2] > 3)
	{
		add_around(grid1, 2, 2);
		grid1[2][2] -= 4;
	}
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
		print_grid1(grid1);
		topple_grid(grid1);
	}
}

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
}
