#!/usr/bin/python3
"""Places N non-attacking queens on an N×N chessboard"""

from sys import argv

if __name__ == "__main__":
    try:
        N = int(argv[1])
    except (IndexError):
        print("Usage: nqueens N")
        exit(1)
    except (ValueError):
        print("N must be a number")
        exit(1)
    if (N < 4):
        print("N must be at least 4")
        exit(1)
