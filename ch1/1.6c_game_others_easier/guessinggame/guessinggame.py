import sys

lines = sys.stdin.readlines()

lo = 1
hi = 10

n = int((len(lines) - 1) / 2)

for i in range(n):
    guess = int(lines[2*i].strip())
    response = lines[2*i+1].strip()

    if (response == "too high"):
        if (guess <= hi): hi = guess - 1
    if (response == "too low"):
        if (guess >= lo): lo = guess + 1
    if (response == "right on"):
        if (hi < lo or guess > hi or guess < lo):
            print("Stan is dishonest")
        else:
            print("Stan may be honest")
        lo = 1
        hi = 10

