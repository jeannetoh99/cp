import sys

def drawHorizontalLine(r, c1, c2, board):
    if (c2 < c1): [c1, c2] = [c2, c1]
    for c in range(c1 + 1, c2):
        if (board[r][c] == '.'):
            board[r][c] = '-'
        elif (board[r][c] == '|'):
            board[r][c] = '+'
        else:
            continue

def drawVerticalLine(r1, r2, c, board):
    if (r2 < r1): [r1, r2] = [r2, r1]
    for r in range(r1 + 1, r2):
        if (board[r][c] == '.'):
            board[r][c] = '|'
        elif (board[r][c] == '-'):
            board[r][c] = '+'
        else:
            continue

def main():
    cases = sys.stdin.read().strip().split("\n\n")

    dots = [str(i) for i in range(0, 10)]
    dots.extend([chr(i) for i in range(ord('a'), ord('z') + 1)])
    dots.extend([chr(i) for i in range(ord('A'), ord('Z') + 1)])
    
    first = True
    for case in cases:
        case = case.strip()
        if (case == ""): continue
        if (first):
            first = False
        else:
            print()
        lines = case.split("\n")
        board = [[char for char in line] for line in lines]
        rows = len(board)
        cols = len(board[0])

        # Keep track off current dot position (we will find in order from 0)
        rr = 0
        cc = 0
        curr = 0

        # Find '0' to start
        for r in range(rows):
            for c in range(cols):
                if board[r][c] == '0':
                    rr = r
                    cc = c
                    break

        # Keep finding, drawing and moving to next dot until no more
        while (True):
            if (dots[curr] == 'Z'): break
            found = False
            for c in range(cols):
                if board[rr][c] == dots[curr + 1]:
                    drawHorizontalLine(rr, c, cc, board)
                    found = True
                    cc = c
                    curr += 1
                    break
            if found: continue
            for r in range(rows):
                if board[r][cc] == dots[curr + 1]:
                    drawVerticalLine(rr, r, cc, board)
                    found = True
                    rr = r
                    curr += 1
                    break
            if not found: break

        for r in range(rows):
            print("".join(board[r]))

main()