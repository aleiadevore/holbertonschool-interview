#!/usr/bin/python3
"""
Returns perimeter of island represented in grid
"""

# each land represented by 1
# perimeter = 4 for each land square (1p for perimeter of 1)
# 1p -= 1 for each 1 around it

def island_perimeter(grid):
    """ Returns perimeter of island represented in grid """
    if grid == None:
        return 0
    p = 0
    for line in range(0, len(grid) - 1):
        for num in range(0, len(grid[line]) - 1):
            if grid[line][num] == 1:
                p += 4
                # Check for intersections with other 1s
                if line > 0:
                    if grid[line - 1][num] == 1:
                        p -= 1
                if line != len(grid) - 1:
                    if grid[line + 1][num] == 1:
                        p -= 1
                if num > 0:
                    if grid[line][num - 1]:
                        p -= 1
                if num != len(grid[line]) - 1:
                   if grid[line][num + 1]:
                        p -= 1 
    return p
