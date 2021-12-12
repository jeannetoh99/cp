import sys

t = int(input())

for i in range(t):
    [w, h, n] = [int(s) for s in input().split(" ")]
    p1 = []
    p2 = []
    s1 = 0
    s2 = 0
    for r in range(h):
        row = [char for char in input()]
        s1 += row.count('#')
        p1.append(row)
        
    for r in range(h):
        row = [char for char in input()]
        s2 += row.count('#')
        p2.append(row)

    turn = 1
    winnerFound = False
    for s in range(n):
        [x, y] = [int(s) for s in input().split(" ")]
        if (winnerFound): continue
        if (turn == 1):
            if (p2[h-1-y][x] == '#'):
                p2[h-1-y][x] = '_'
                s2 -= 1
                if (s2 == 0): turn = 2
            elif (s1 != 0):
                turn = 2
        elif (turn == 2):
            if (p1[h-1-y][x] == '#'):
                p1[h-1-y][x] = '_'
                s1 -= 1
                if (s1 == 0): winnerFound = True
            elif (s2 != 0):
                turn = 1
            else:
                winnerFound = True
        
    
    if ((s1 > 0 and s2 > 0) or (s1 == 0 and s2 == 0)):
        print("draw")
    elif (s1 == 0):
        print("player two wins")
    else:
        print("player one wins")
    
