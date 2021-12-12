line = input()
line = [char for char in line]

# Policy 1: When you leave, always leave the seat up
p1 = line.count('D') * 2
if (line[0] == 'D'):
    p1 -= 2
    if (line[1] == 'D'):
        p1 -= 1
    else:
        p1 += 1

# Policy 2: When you leave, always leave the seat down
p2 = line.count('U') * 2
if (line[0] == 'U'):
    p2 -= 2
    if (line[1] == 'U'):
        p2 -= 1
    else:
        p2 += 1

# Policy 3: When you leave, always leave the seat as you would like to find it
p3 = 0
for i in range(1, len(line)):
    if (line[i-1] != line[i]): p3 += 1

print(p1)
print(p2)
print(p3)