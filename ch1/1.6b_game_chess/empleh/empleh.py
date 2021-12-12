import sys

white = sys.stdin.readline().strip()[7:].split(",")
black = sys.stdin.readline().strip()[7:].split(",")

board = [['-']*8 for i in range(8)]

if (white[0] != ''):
    for pos in white:
        if (len(pos) == 3):
            [p,c,r] = [char for char in pos]
            board[int(r)-1][ord(c) - ord('a')] = p
        else:
            [c,r] = [char for char in pos]
            board[int(r)-1][ord(c) - ord('a')] = 'P'
if (black[0] != ''):
    for pos in black:
        if (len(pos) == 3):
            [p,c,r] = [char for char in pos]
            board[int(r)-1][ord(c) - ord('a')] = chr(ord('a') + (ord(p) - ord('A')))
        else:
            [c,r] = [char for char in pos]
            board[int(r)-1][ord(c) - ord('a')] = 'p'

hline = "+---+---+---+---+---+---+---+---+"

for r in range(7,-1,-1):
    print(hline)
    row = list("|")
    for c in range(0,8):
        if (r % 2 == c % 2): 
            row.append(":")
            if board[r][c] == '-':
                row.append(":")
            else:
                row.append(board[r][c])
            row.append(":|")
        else:
            row.append(".")
            if board[r][c] == '-':
                row.append(".")
            else:
                row.append(board[r][c])
            row.append(".|")
    print("".join(row))
print(hline)
        
