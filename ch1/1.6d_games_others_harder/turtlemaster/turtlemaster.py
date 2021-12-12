import sys

directions = ['right', 'up', 'left', 'down']
delta = [[1, 0], [0, 1], [-1, 0], [0, -1]]

def X(board, r, c, d):
    
    c = c + delta[d][0]
    r = r + delta[d][1]
    if (c < 0 or c >= 8 or r < 0 or r >= 8): return True
    if (board[r][c] == 'I'):
        board[r][c] = '.'
        return False
    return True


def L(d):
    # print("L")
    return (d + 1) % 4

def R(d):
    # print("R")
    return (d + 4 - 1) % 4

def F(board, r, c, d):
    # print("F")
    c = c + delta[d][0]
    r = r + delta[d][1]

    if (c < 0 or c >= 8 or r < 0 or r >= 8 or board[r][c] == 'C' or board[r][c] == 'I'):
        return [r,c,d,True]
    else:
        return [r,c,d,False]

def main():
    lines = sys.stdin.readlines()
    board = [[char for char in line.strip()] for line in lines[7::-1]]
    moves = [char for char in lines[8].strip()]

    r = 0
    c = 0
    d = 0

    for move in moves:
        if (move == 'F'):
            [r,c,d,bug] = F(board, r, c, d)
            if (bug):
                print("Bug!")
                return
        elif (move == 'R'):
            d = R(d)
        elif (move == 'L'):
            d = L(d)
        else:
            bug = X(board, r, c, d)
            if (bug):
                print("Bug!")
                return
    
    if (board[r][c] == 'D'):
        print("Diamond!")
    else:
        print("Bug!")

main()