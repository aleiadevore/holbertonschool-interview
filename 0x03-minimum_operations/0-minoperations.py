#!/usr/bin/python3
"""Checks minimum number of operations needed"""
import math

def minOperations(n):
    ans = math.log(n, 2)

    if ans:
        return round(ans * 2)
    return 0