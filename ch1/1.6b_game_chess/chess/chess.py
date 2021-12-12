import sys

def isBlack(c, r):
    return c % 2 == r % 2

def canMove(c1, r1, c2, r2):
    return abs(c1 - c2) == abs(r1 - r2)

def main():

    N = int(sys.stdin.readline().strip())

    for line in sys.stdin:
        [c1, r1, c2, r2] = line.split(" ")
        c1 = ord(c1) - ord('A')
        r1 = int(r1) - 1
        c2 = ord(c2) - ord('A')
        r2 = int(r2) - 1

        found = False
        if isBlack(c1, r1) != isBlack(c2, r2):
            print("Impossible")
        elif (c1 == c2 and r1 == r2):
            print(0, chr(c1 + ord('A')), r1 + 1)
        elif (abs(c1 - c2) == abs(r1 - r2)):
            print(1, chr(c1 + ord('A')), r1 + 1, chr(c2 + ord('A')), r2 + 1)
        else:
            for c3 in range(0,8):
                for r3 in range(0,8):
                    if canMove(c1, r1, c3, r3) and canMove(c3, r3, c2, r2):
                        print(2, chr(c1 + ord('A')), r1 + 1, chr(c3 + ord('A')), r3 + 1, chr(c2 + ord('A')), r2 + 1)
                        found = True
                        break
                if found: break

main()