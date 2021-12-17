import statistics
import math
import datetime
import collections

def solve():
    prog = [char for char in input().strip()]
    n = int(input())
    line = input().strip()
    if n == 0:
        l = []
    else:
        l = line[1:-1].split(",")
    l = collections.deque(l)

    rev = False
    for p in prog:
        if (p == 'R'): 
            rev = not rev
        else:
            if (len(l) == 0):
                print("error")
                return
            if rev:
                l.pop()
            else:
                l.popleft()
    if rev:
        l.reverse()
    print("[" + ",".join(map(str,l)) + "]")

def main():
    t = int(input())
    for i in range(t):
        solve()

main()