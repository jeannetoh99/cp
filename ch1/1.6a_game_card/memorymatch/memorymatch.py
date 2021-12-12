import sys

cards = {}

def addCard(c, p):
    if (cards.get(p) == None):
        cards[p] = set()
    cards[p].add(c)

def main():
    N = int(sys.stdin.readline().strip())
    K = int(sys.stdin.readline().strip())

    matched = 0
    for line in sys.stdin.readlines():
        [c1, c2, p1, p2] = line.strip().split(" ")
        if (p1 == p2): matched += 1
        addCard(c1, p1)
        addCard(c2, p2)

    pairs = 0
    singles = 0
    opened = 0
    for card in cards.values():
        if len(card) == 2: pairs += 1
        else: singles += 1
        opened += len(card)

    unopened = N - opened
    found = pairs - matched
    if (singles == unopened): # can open unopened and match with singles
        print(found + unopened)
    elif (singles == 0 and unopened == 2): # unopened pair is a match
        print(found + 1)
    else: # can only match from opened but unmatched pairs
        print(found)

main()