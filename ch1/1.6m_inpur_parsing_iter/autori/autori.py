line = input()
line = line.split("-")
res = [word[0] for word in line]
res = "".join(res)

print(res)
