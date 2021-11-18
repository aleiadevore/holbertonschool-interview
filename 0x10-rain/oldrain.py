#!/usr/bin/python3
"""
Determines rain held between walls
"""

def checkpeak(walls, i):
    val = walls[i]

    while val > 0:
        j = i + 1
        # print("val: {0}".format(val))
        while (j < len(walls)):
            if walls[j] >= val:
                return j
            j += 1
        val -= 1
    return -1

def rain(walls):
    rain = 0

    i = 0
    while(i < len(walls) - 1):
        # print("i: {0}".format(i))
        if (walls[i] == 0):
            i += 1
            continue
        # Change to flood over shorter walls
        else:
            j = i + 1
            mult = 0
            while (walls[j] == 0 and j < len(walls) - 1):
                mult += 1
                j += 1
            peak = checkpeak(walls, i)
            if peak > 0:
                print("Peak: {0}".format(peak))
                j = i + 1
                if walls[i] < walls[peak]:
                    add = walls[i]
                else:
                    add = walls[j]
                while (j < peak):
                    rain += add - walls[j]
                    j += 1
                i = peak
            else:
                if walls[i] < walls[j]:
                    #print("{0} += {1} * {2}".format(rain, walls[i], mult))
                    rain += (walls[i] * mult)
                else:
                    #print("{0} += {1} * {2}".format(rain, walls[j], mult))
                    rain += (walls[j] * mult)
                i += 1
        #print("Rain: {0}".format(rain))
    return rain
