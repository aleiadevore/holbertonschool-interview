#include "slide_line.h"
/**
 * slide_line - slides numbers in array left or right. Ident. numbers merged
 *
 * @line: single array with ints to slide
 * @size: number of elements
 * Return: 1 on success, 0 on fail
 */

int slide_line(int *line, size_t size, int direction)
{
    int s = size;
    if (direction == SLIDE_LEFT)
        return (slide_left(line, s));
    else if (direction == SLIDE_RIGHT)
        return (slide_right(line, s));
    else
        return 0;
}

/**
 * slide_left - slides line left
 *
 * @line - line to slide
 * @size - size of line
 *
 * Return: 1 on success 0 on failure
 */

int slide_left(int *line, int size)
{
    int prev = 0, i, dup_count = 0, newI = 0;
    int new[size];

    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            if (line[i] == prev && dup_count == 1)
            {
                new[newI] = prev * 2;
                newI++;
                prev = 0;
                dup_count = 0;
            }
            else if (line[i] != prev && prev != 0)
            {
                new[newI] = prev;
                newI++;
                prev = line[i];
                dup_count = 1;
            }
            else
            {
                dup_count++;
                prev = line[i];
            }
        }
    }

    if (dup_count != 0)
    {
        new[newI] = prev;
        newI++;
    }
    /* Filling in rest of new */
    for (; newI < size; newI++)
        new[newI] = 0;

    for (i = 0; i < size; i++)
        line[i] = new[i];

    return (1);
}

/**
 * slide_right - slides line right
 *
 * @line - line to slide
 * @size - size of line
 *
 * Return: 1 on success 0 on failure
 */

int slide_right(int *line, int size)
{
    int prev = 0, i, dup_count = 0, newI = size - 1;
    int new[size];

    for (i = size - 1; i >= 0; i--)
    {
        if (line[i] != 0)
        {
            if (line[i] == prev && dup_count == 1)
            {
                new[newI] = prev * 2;
                newI--;
                prev = 0;
                dup_count = 0;
            }
            else if (line[i] != prev && prev != 0)
            {
                new[newI] = prev;
                newI--;
                prev = line[i];
                dup_count = 1;
            }
            else
            {
                dup_count++;
                prev = line[i];
            }
        }
    }

    if (dup_count != 0)
    {
        new[newI] = prev;
        newI--;
    }
    /* Filling in rest of new */
    for (; newI >= 0; newI--)
        new[newI] = 0;

    for (i = 0; i < size; i++)
        line[i] = new[i];

    return (1);
}
