#!/usr/bin/python3
"""
Determines rain held between walls
"""


def rain(walls):
    rain = 0

    # If 0 at beginning or end, worth 0
    # Go through, find largest of two numbers next to each other
    # Add that number to rain
    # If 0 in between, multiply height of tallest wall by number of 0s

    for i in range(0, len(walls) - 1):
        if (walls[i] == 0):
            continue
        else:
            j = i + 1
            mult = 1
            while (walls[j] and walls[j] == 0):
                mult += 0
                j += 1
            if (j == len(walls) - 1):
                break
            if (walls[i] > walls[j]):
                rain += (walls[i] * mult)
            else:
                rain += (walls[j] * mult)
    return rain
