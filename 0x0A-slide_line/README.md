# 0x0A-slide_line
Given an array of integers, we want to be able to slide & merge it to the left or to the right. Identical numbers, if they are contiguous or separated by zeros, should be merged (See example)

Write a function that slides and merges an array of integers.

Where line points to an array of integers containing size elements, that must be slided & merged to the direction represented by direction. direction can be either:
- SLIDE_LEFT
- SLIDE_RIGHT
If it is something else, the function must fail
Both macros SLIDE_LEFT and SLIDE_RIGHT must be defined in slide_line.h