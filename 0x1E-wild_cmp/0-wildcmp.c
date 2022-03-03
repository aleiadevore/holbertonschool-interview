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
	/* If it's reached this point, it's a match */
	if (*s1 == 0 && *s2 == 0)
		return (1);
	/* If characters are the same, check with next chars */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 2));
	
	/* Check for wildcard */
	if (*s2 != '*')
		return (0);
	return (1);
}
