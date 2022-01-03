#!/usr/bin/python3
"""
Rotates a matrix 90 degrees clockwise
"""


def rotate_2d_matrix(matrix):
    """
    Rotates (in place) a matrix 90 degrees clockwise
    """
    # Rows will become columns, with first row being last column
    # Easier to manip: columns will become rows, w/ first col as first row

    # reversed: makes shallow reversed copy
    # *: unpacks each sublist
    # zip: transposes by making tuples with one item from each list
    new = list(zip(*reversed(matrix)))
    for i in range(0, len(new) - 1):
        for j in range(0, len(new[0]) - 1):
            matrix[i][j] = new[i][j]
