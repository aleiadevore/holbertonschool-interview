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
 * check_string - checks if string is int or 0
 * @argv: input string
 *
 * Return: -1 if error, 1 if valid string, 0 if one string is 0
 */
int check_string(char *argv[])
{
	int i, j, z_check = 0;

	for (i = 1; i < 3; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				print_error();
				return (-1);
			}
			if (argv[i][j] != '0')
				z_check++;
		}
		if (z_check == 0)
			return (0);
		z_check = 0;
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
	int str_check, ans = 0;
	/*int a[100], b[100];*/

	if (argc != 3)
	{
		print_error();
		return (98);
	}

	str_check = check_string(argv);
	if (str_check < 0)
		return (98);
	if (str_check == 0)
	{
		_putchar('0');
		_putchar('\n');
	}

	return (ans);
}
