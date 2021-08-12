#!/usr/bin/python3
"""Checks minimum number of operations needed"""
import math


def minOperations(n):
    try:
        ans = math.log(n, 2)
        return round(ans * 2)
    except:
        return 0
