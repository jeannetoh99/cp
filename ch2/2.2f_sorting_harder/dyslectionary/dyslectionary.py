import sys
from functools import cmp_to_key


l = list()
for line in sys.stdin.readlines():
    if (not line.strip()):
        l = sorted(l, key=lambda x: x[::-1])
        ml = max(map(len, l))
        print("\n".join([c.rjust(ml) for c in l]))
        print()
        l = list()
    else:
        l.append(line.strip())

l = sorted(l, key=lambda x: x[::-1])
ml = max(map(len, l))
print("\n".join([c.rjust(ml) for c in l]))