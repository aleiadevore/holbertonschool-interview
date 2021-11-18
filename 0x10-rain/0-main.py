#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(walls)
    print("Answer: {0}".format(rain(walls)))
    print("Expected: 6\n")
    
    walls = [2, 0, 0, 4, 0, 0, 1, 0]
    print(walls)
    print("Answer: {0}".format(rain(walls)))
    print("Expected: 6\n")
    
    walls = [1, 1, 2, 0, 1, 1, 1]
    print(walls)
    print("Answer: {0}\n".format(rain(walls)))
    
    walls = [0, 2, 1, 0, 1, 3, 1, 2, 1, 1, 2, 1]
    print(walls)
    print("Answer: {0}\n".format(rain(walls)))
    
    walls = [2, 0, 0, 0, 0, 3, 0]
    print(walls)
    print("Answer: {0}".format(rain(walls)))
    print("Expected: 8\n")
    
    walls = [0, 2, 1, 0, 1, 3, 1, 2, 1, 1, 2, 1]
    print(walls)
    print("Answer: {0}".format(rain(walls)))
    print("Expected: 7\n")
