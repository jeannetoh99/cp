import sys

numToString = {
    0: 'xxxxxx...xx...xx...xx...xx...xxxxxx',
    1: '....x....x....x....x....x....x....x',
    2: 'xxxxx....x....xxxxxxx....x....xxxxx',
    3: 'xxxxx....x....xxxxxx....x....xxxxxx',
    4: 'x...xx...xx...xxxxxx....x....x....x',
    5: 'xxxxxx....x....xxxxx....x....xxxxxx',
    6: 'xxxxxx....x....xxxxxx...xx...xxxxxx',
    7: 'xxxxx....x....x....x....x....x....x',
    8: 'xxxxxx...xx...xxxxxxx...xx...xxxxxx',
    9: 'xxxxxx...xx...xxxxxx....x....xxxxxx',
}

stringToNum = {
    'xxxxxx...xx...xx...xx...xx...xxxxxx': 0,
    '....x....x....x....x....x....x....x': 1,
    'xxxxx....x....xxxxxxx....x....xxxxx': 2,
    'xxxxx....x....xxxxxx....x....xxxxxx': 3,
    'x...xx...xx...xxxxxx....x....x....x': 4,
    'xxxxxx....x....xxxxx....x....xxxxxx': 5,
    'xxxxxx....x....xxxxxx...xx...xxxxxx': 6,
    'xxxxx....x....x....x....x....x....x': 7,
    'xxxxxx...xx...xxxxxxx...xx...xxxxxx': 8,
    'xxxxxx...xx...xxxxxx....x....xxxxxx': 9,
}

lines = [line.strip() for line in sys.stdin.readlines()]

a = 0
b = 0

isA = True
for i in range(int((len(lines[0]) + 1) / 6)):
    numStr = list()
    for j in range(7):
        numStr.append(lines[j][i*6:i*6+5])
    numStr = "".join(numStr)
    if (numStr not in stringToNum.keys()):
        isA = False
    elif (isA):
        a = (a*10)+stringToNum[numStr]
    else:
        b = (b*10)+stringToNum[numStr]

sum = str(a + b)

for i in range(7):
    line = ''
    for j in range(len(sum)):
        line += numToString[int(sum[j])][i*5:i*5+5] + '.'
    print(line[:-1])