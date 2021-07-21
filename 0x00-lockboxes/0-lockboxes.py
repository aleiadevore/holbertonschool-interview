#!/usr/bin/python3
"""Determines if all boxes can be opened, beginning with 0"""


def canUnlockAll(boxes):
    # array to store all keys captured
    allKeys = {
        0: True
    }
    # number of times going through loop
    trips = 0

    for i in range(1, len(boxes)):
        allKeys[i] = False

    # loop through all keys captured
    while False in allKeys.values() and trips < len(boxes):
        for i in allKeys:
            if allKeys[i] is True:
                for k in boxes[i]:
                    if k > 0 and k < len(boxes):
                        allKeys[k] = True
                trips += 1

    if False in allKeys.values():
        return False
    return True
