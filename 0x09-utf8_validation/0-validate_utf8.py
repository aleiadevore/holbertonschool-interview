#!/usr/bin/python3
"""
Returns True if data is valid UTF-8 encoding, otherwise returns False
"""

def validUTF8(data):
    # If byte starts UTF-8 char, process first N bits with N <= 4
    # If N > 4, return False
    N = 0

    # Only check first two (most significant) bits
    # Most significant must = 1
    check1 = 1 << 7
    # second most significant must = 0
    check2 = 1 << 6

    for i in data:
        bit = 1 << 7
        if N == 0:
            while bit & i:
                N += 1
                bit = bit >> 1

            # Char is only one byte
            if N == 0:
                continue

            # Invalid byte
            if N == 1 or N > 4:
                return False
        else:
            # Checking if first two bits are correct
            if not (i & check1 and not (i & check2)):
                return False
        # Repeat cycle for next largest bit in multibit char
        N -= 1
    return N == 0


