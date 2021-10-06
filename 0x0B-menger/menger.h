#ifndef MENGER_H
#define MENGER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menger(int level);
void make_menger(int level, int place, char **sponge);
char **make_sub(char **sub_array, int subsize);
void print_menger(char **sponge, int row_size);

#endif /* MENGER_H */
