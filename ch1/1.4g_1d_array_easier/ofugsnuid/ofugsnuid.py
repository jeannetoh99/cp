import sys

n = int(input())
l = list()

for i in range(n):
    l.append(input())

l.reverse()

for i in range(n):
    print(l[i])