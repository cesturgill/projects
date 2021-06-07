import sys
import math

cases = int(input())

for i in range(0, cases):
    args = input().split(' ')
    sides = int(args[0])
    sidelength = int(args[1])
    grablength = int(args[2])
    grabs = int(args[3])
    radius = grablength * grabs
    perim = sidelength * sides
    apothem = sidelength / (2 * math.tan(math.radians(180 / sides)))
    area = perim * apothem / 2
    area = area + radius * sidelength * sides + radius * radius * math.pi
    print(area)
