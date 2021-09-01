#!/usr/bin/python3
"""Parses lines from standard input"""
import sys
import fileinput

i = 0
filesize = 0

status = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}

try:
    for line in fileinput.input():
        i += 1
        delim = line.split()
        status[delim[7]] += 1
        if i % 10 == 0:
            filesize += int(delim[8])
            print("File size: {}".format(filesize))
            for item in sorted (status.items()):
                if item[1] != 0:
                    print("{}: {}".format(item[0], item[1]))
    print("File size: {}".format(filesize))
    for item in sorted (status.items()):
        if item[1] != 0:
            print("{}: {}".format(item[0], item[1]))
except KeyboardInterrupt:
    print("File size: {}".format(filesize))
    for item in sorted (status.items()):
        if item[1] != 0:
            print("{}: {}".format(item[0], item[1]))
