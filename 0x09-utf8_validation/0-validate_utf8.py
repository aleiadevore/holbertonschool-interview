#!/usr/bin/python3
"""
Returns True if data is valid UTF-8 encoding, otherwise returns False
"""

def validUTF8(data):
    for item in data:
        if (item >= 256):
            return False
    return True
