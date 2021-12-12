import sys

mapping = {
    "111101101101111": 0,
    "001001001001001": 1,
    "111001111100111": 2,
    "111001111001111": 3,
    "101101111001001": 4,
    "111100111001111": 5,
    "111100111101111": 6,
    "111001001001001": 7,
    "111101111101111": 8,
    "111101111001111": 9,
}


code = [ [ line[i*4:i*4+4][:3].replace('*', '1').replace(' ', '0') for i in range(int(len(line) / 4))] for line in sys.stdin.readlines()]

num = 0
for c in range(0, len(code[0])):
    digit = ""
    for r in range(0,5):
        digit += code[r][c]
    try:
        digit = mapping[digit]
        num = num * 10 + digit
    except KeyError:
        print("BOOM!!")
        exit(0)

if (num % 6 == 0):
    print("BEER!!")
else:
    print("BOOM!!")

