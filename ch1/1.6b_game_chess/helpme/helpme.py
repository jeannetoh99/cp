import sys
from functools import cmp_to_key

lines = sys.stdin.readlines()

white = list()
black = list()

for i in range(0,8):
    col = lines[i*2 + 1].strip().split("|")[1:-1:1]
    r = 7 - i
    for c in range(0,8):
        p = col[c][1]
        if (p == '.' or p == ':'):
            continue
        elif (p == 'p' or p == 'P'):
            if (ord(p) < ord('a')):
                white.append("%s%s" % (chr(ord('a') + c), r + 1))
            else:
                black.append("%s%s" % (chr(ord('a') + c), r + 1))
        else:
            if (ord(p) < ord('a')):
                white.append("%s%s%s" % (p, chr(ord('a') + c), r + 1))
            else:
                black.append("%s%s%s" % (chr(ord('A') + ord(p) - ord('a')), chr(ord('a') + c), r + 1))

def whitecompare(item1, item2):
    order = {
        "K": 0,
        "Q": 1,
        "R": 2,
        "B": 3,
        "S": 4,
        "N": 5
    }
    if (len(item1) == len(item2)):
        if len(item1) == 3:
            if (order[item1[0]] == order[item2[0]]):
                if (item1[2] == item2[2]):
                    return ord(item1[1]) - ord(item2[1])
                else:
                    return ord(item1[2]) - ord(item2[2])
            else:
                return order[item1[0]] - order[item2[0]]
        else:
            if (item1[1] == item2[1]):
                return ord(item1[0]) - ord(item2[0])
            else:
                return ord(item1[1]) - ord(item2[1])
    else:
        return len(item2) - len(item1)

def blackcompare(item1, item2):
    order = {
        "K": 0,
        "Q": 1,
        "R": 2,
        "B": 3,
        "S": 4,
        "N": 5
    }
    if (len(item1) == len(item2)):
        if len(item1) == 3:
            if (order[item1[0]] == order[item2[0]]):
                if (item1[2] == item2[2]):
                    return ord(item1[1]) - ord(item2[1])
                else:
                    return ord(item2[2]) - ord(item1[2])
            else:
                return order[item1[0]] - order[item2[0]]
        else:
            if (item1[1] == item2[1]):
                return ord(item1[0]) - ord(item2[0])
            else:
                return ord(item2[1]) - ord(item1[1])
    else:
        return len(item2) - len(item1)

white = sorted(white, key=cmp_to_key(whitecompare))
black = sorted(black, key=cmp_to_key(blackcompare))

print("White:", ",".join(white))
print("Black:", ",".join(black))
    
