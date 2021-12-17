import sys

def solve(a, b):
    i = 0
    res = 0
    carry = 0
    while (i < len(a) and i < len(b)):
        sum = a[i] + b[i] + carry
        carry = int(sum / 10)
        if (carry > 0): res += 1
        i += 1

    while (i < len(a)):
        sum = a[i] + carry
        carry = int(sum / 10)
        if (carry > 0): res += 1
        i += 1

    while (i < len(b)):
        sum = b[i] + carry
        carry = int(sum / 10)
        if (carry > 0): res += 1
        i += 1
    
    return res


for line in sys.stdin.readlines():
    [a, b] = line.strip().split(' ')
    if (a == '0' and b == '0'): break
    a = [int(char) for char in a]
    a.reverse()
    b = [int(char) for char in b]
    b.reverse()

    res = solve(a, b)

    if (res == 0):
        print("No carry operation.")
    elif (res == 1):
        print("1 carry operation.")
    else:
        print(res, "carry operations.")