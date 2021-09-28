#ifndef SLIDE_H
#define SLIDE_H

#define SLIDE_LEFT 299
#define SLIDE_RIGHT 382

#include <stdlib.h>
#include <stdio.h>

int slide_line(int *line, size_t size, int direction);
int slide_left(int *line, int size);
int slide_right(int *line, int size);

#endif /*SLIDE_H*/
