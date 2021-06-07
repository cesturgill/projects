import sys

books = int(input())
booklist = []
for i in range(0, books):
    booklist.append(int(input()))
booklist.sort()
booklist.reverse()
cost = 0
index = 1
for j in range(0, books):
    if index % 3 != 0:
        cost = cost + booklist[j]
    index += 1
print(cost)
