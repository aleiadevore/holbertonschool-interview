#!/usr/bin/python3
"""Checks minimum number of operations needed"""
import math


def minOperations(n):
    if n <= 0 or n == 1:
        return 0
    """if n % 2 == 0:
        try:
            ans = math.log(n, 2)
            return round(ans * 2)
        except:
            return 0"""

    if n == 3:
        return 3
    if n == 1:
        return 0
    cs = 2
    ops = 0

    while (cs * cs <= n):
        if math.log(n, cs).is_integer():
            ops += math.log(n, cs) * 2
            return round(ops) + cs + 1
        if (n % cs == 0):
            n /= cs
            ops += cs
        else:
            cs += 1
    if n >= 2:
        ops += n
    return round(ops)
