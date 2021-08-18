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
}
