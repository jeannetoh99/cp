qn = input()
n = int(input())
options = list()
for i in range(n):
    opt = input().strip().split(", ")
    options.append(opt)

parts = len(options[0])
minincon = -1
minchange = 1000

res = list()

for i in range(n):
    maxchange = 0
    for k in range(n):
        changes = 0
        for j in range(parts):
            if (i == k): continue
            if (options[i][j] != options[k][j]):
                changes += 1
        maxchange = max(maxchange, changes)
    if (maxchange < minchange): 
        res = [i]
        minchange = maxchange
    elif (maxchange == minchange):
        res.append(i)

for i in res:
    print(", ".join(options[i]))

