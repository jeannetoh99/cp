import sys

scores = {
    "A": [11, 11],
    "K": [4, 4],
    "Q": [3, 3],
    "J": [20, 2],
    "T": [10, 10],
    "9": [14, 0],
    "8": [0, 0],
    "7": [0, 0],
}

[N, B] = sys.stdin.readline().strip().split(" ")
total = 0

lines = sys.stdin.readlines()
for line in lines:
    val = line[0]
    suit = line[1]
    if (suit == B):
        total += scores[val][0]
    else:
        total += scores[val][1]

print(total)