import sys
import math

cases = int(input())

for i in range(0, cases):
    args = input().split(' ')
    grades = int(args[0])
    total = 0
    for j in range(1, (grades + 1)):
        total = total + int(args[j])
    avg = total / grades
    above = 0
    for k in range(1, (grades + 1)):
        if int(args[k]) > avg:
            above = above + 1
    abovepercent = above / grades * 100
    print('{0:.3f}%'.format(abovepercent))
