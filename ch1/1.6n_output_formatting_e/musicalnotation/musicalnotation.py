n = int(input())

stafflines = {}

for i in range(7):
    lower = chr(ord('a') + i)
    upper = chr(ord('A') + i)
    stafflines.update({lower: list(), upper: list()})

notes = input().strip().split()

dash = ['F', 'D', 'B', 'g', 'e', 'a']

for note in notes:
    t = 1
    if (len(note) > 1): t = int(note[1:])
    note = note[0]
    for k in stafflines.keys():
        if (k != note and k in dash): stafflines[k].append('-'*(t+1))
        elif (k != note and k not in dash): stafflines[k].append(' '*(t+1))
        else: stafflines[k].append('*'*t + ('-' if k in dash else ' '))

keys = ['G', 'F', 'E', 'D', 'C', 'B', 'A', 'g', 'f', 'e', 'd', 'c', 'b', 'a']

for key in keys:
    print(key + ":", "".join(stafflines[key])[:-1])

