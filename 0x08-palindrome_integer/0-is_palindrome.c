#include "palindrome.h"

/**
 * is_palindrome - checks if int is palindrome
 * @n: int to check
 * 
 * Return - 1 if palindrome, otherwise 0
 */

int is_palindrome(unsigned long n)
{
	int a;

	a = palindrome_check(n);

	if (a < 0)
		return 0;
	return 1;
}

int palindrome_check(long n)
{
	int first, last;

	if (n < 0)
		return (-1);
	if (n < 10)
		return (1);

	for (first = n; first >= 10; first = first / 10)
	{
		/*printf("%d\n", first);*/
	}
	/*first /= 10;*/
	last = n % 10;
	/*printf("First: %d\nLast: %d\n", first, last);
	printf("__________\n");*/
	if (n % 10 != first)
		return (-1);
	else
	{
		n %= 10;
		return palindrome_check(n / 10);
	}
}
