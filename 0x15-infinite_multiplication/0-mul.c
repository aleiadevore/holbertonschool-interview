#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_error - prints error message
 *
 * Return: void
 */
void print_error(void)
{
	char *e = "Error\n";
	int i;

	for (i = 0; i < 6; i++)
		_putchar(e[i]);
}

/**
 * check_string - checks if string is int
 * @argv: input string
 *
 * Return: -1 if error, 1 if valid string
 */
int check_string(char *argv[])
{
	int i, j;

	for (i = 1; i < 3; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				print_error();
				return (-1);
			}
		}
	}
	return (1);
}

/**
 * main - main function
 * @argc: number of user inputs
 * @argv: array of user inputs
 *
 * Return: 98 on error, else 1
 */

int main(int argc, char *argv[])
{
	/*int a[100], b[100];*/

	if (argc != 3)
	{
		print_error();
		return (98);
	}

	if (check_string(argv) < 0)
		return (98);

	return (1);
}
