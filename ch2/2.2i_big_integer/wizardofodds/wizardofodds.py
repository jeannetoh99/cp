import math

[n, k] = [int(ch) for ch in input().strip().split()]
logn = math.log(n, 2)

if (k >= logn):
    print("Your wish is granted!")
else:
    print("You will become a flying monkey!")