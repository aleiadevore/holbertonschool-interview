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

    """First approach -- brute force and backtracking"""
    allQueens = dict()

    def ResetDict():
        # Create dict to store locations of queens
        for i in range(0, N):
            allQueens[i] = ()

    def IterateFirst(startJ):
        usedJ = []
        allQueens[0] = (0, startJ)
        usedJ.append(startJ)

        for i in range(1, N):
            if len(allQueens[i - 1]) != 2:
                # print("Resetting")
                return False
            for j in range(0, N):
                # print("[{}, {}]".format(i, j))
                if j in usedJ:
                    # print("j has been used")
                    continue
                if i > 0:
                    prevJ = allQueens[i - 1][1]
                    if j == prevJ - 1 or j == prevJ + 1:
                        # print("j is {} and prevJ is {}".format(j, prevJ))
                        continue
                allQueens[i] = (i, j)
                usedJ.append(j)
                if (i == N - 1):
                    return True
                i += 1

    def PrintDict():
        print("[", end="")
        print(", ".join("[{}, {}]".format(
            v[0], v[1]) for k, v in allQueens.items()), end="]\n")

    for startJ in range(0, N):
        # print("In outer loop, startJ is {}".format(startJ))
        ResetDict()
        if IterateFirst(startJ):
            PrintDict()
