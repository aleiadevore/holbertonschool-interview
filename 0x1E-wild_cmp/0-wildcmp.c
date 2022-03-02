#include "holberton.h"

/**
 * wildcmp - Compares two strings
 * @s1: first string
 * @s2: second string, can contain a wildcard
 *
 * Return: 1 if strings identical, else 0
 */

int wildcmp(char *s1, char *s2)
{
	int i, j;

	/* First working with no wildcard */

	for (i = 0, j = 0; s1[i] != 0; i++, j++)
	{
		/* If s2 runs out of chars before checking complete */
		if (!s2[j])
		{
			/*printf("s2 out of chars\n");*/
			return (0);
		}
		if (s1[i] != s2[j])
		{
			/* If difference isn't caused by wildcard */
			if (s2[j] != 42)
			{
				/*printf("%s: i = %d\n", s1, i);
				printf("%c doesn't = %c\n", s1[i], s2[j]);*/
				return (0);
			}
			/* If diff is *, iterate through s1 until strings match again */
			/*printf("\nIterating s2\n");*/
			while (s2[j] == 42)
			{
				/*printf("%c\n", s2[j]);*/
				if (s2[j] == 0)
					return (1);
				j++;
			}
			/*printf("\nIterating s1\n");*/
			while (s1[i] != s2[j] && s1[i] != 0)
			{
				/*printf("%c != %c\n", s1[i], s2[j]);*/
				i++;
			}
		}
	}

	return (1);
}
