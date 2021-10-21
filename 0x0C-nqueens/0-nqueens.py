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

    def ResetDict(lastQ):
        # Create dict to store locations of queens
        # print("\n\n")
        for i in range(N - 1, lastQ, -1):
            # print(i)
            allQueens[i] = ()
        # print(allQueens)

    def DiagDetect(i, j):
        k = j
        # checks left
        for Qi in range(i - 1, -1, -1):
            if allQueens[Qi][1] == j - 1:
                return False
            j -= 1
        # checks right
        for Qi in range(i - 1, -1, -1):
            if allQueens[Qi][1] == k + 1:
                return False
            k += 1
        return True

    def IterateFirst(startJ, lastQ):
        usedJ = []
        # print("Restarting usedJ with: {}".format(allQueens.items()))
        for q in allQueens.values():
            if len(q) == 2:
                usedJ.append(q[1])
        allQueens[0] = (0, startJ)
        usedJ.append(startJ)
        # print("usedJ: {}".format(usedJ))
        # Quick diag check for main lines. Replace with diag check method

        for i in range(lastQ + 1, N):
            # print("LastQ: {}".format(lastQ))
            # print("i is {}".format(i))
            if len(allQueens[i - 1]) != 2:
                # print("Resetting")
                return False
            for j in range(0, N):
                # print("[{}, {}]".format(i, j))
                if j in usedJ:
                    # print(usedJ)
                    # print("j has been used")
                    continue
                if i > 0:
                    prevJ = allQueens[i - 1][1]
                    if j == prevJ - 1 or j == prevJ + 1:
                        # print("j is {} and prevJ is {}".format(j, prevJ))
                        continue
                if DiagDetect(i, j) is False:
                    # print("False")
                    continue
                allQueens[i] = (i, j)
                usedJ.append(j)
                if (i == N - 1):
                    return True
                i += 1

    def PrintDict():
        print("[", end="")
        print(", ".join("[{}, {}]".format(
            v[0], v[1]) for k, v in sorted(allQueens.items())), end="]\n")

    # for startJ in range(0, N):
    for startJ in range(0, N):
        for lastQ in range(0, N - 2):
            # print("In outer loop, startJ: {}, lastQ: {}".format(
            # startJ, lastQ))
            # print(sorted(allQueens.items()))
            ResetDict(lastQ)
            if IterateFirst(startJ, lastQ):
                PrintDict()
            """else:
                print("Didn't work:")
                print(sorted(allQueens.items()))"""
