base = {
    1: "I",
    2: "II",
    3: "III",
    4: "IV",
    5: "V",
    6: "VI",
    7: "VII",
    8: "VIII",
    9: "IX",
    10: "X",
    20: "XX",
    30: "XXX",
    40: "XL",
    50: "L",
    60: "LX",
    70: "LXX",
    80: "LXXX",
    90: "XC",
    100: "C",
    200: "CC",
    300: "CCC",
    400: "CD",
    500: "D",
    600: "DC",
    700: "DCC",
    800: "DCCC",
    900: "CM",
    1000: "M"
}

val = {}
romans = []

for i in range(1,1001):
    j = i
    hundreds = base[int(i / 100) * 100] if i >= 100 else ""
    i -= int(i / 100) * 100
    tens = base[int(i / 10) * 10] if i >= 10 else ""
    i -= int(i / 10) * 10
    ones = base[i] if i >= 1 else ""
    val[j] = hundreds + tens + ones
    romans.append(hundreds + tens + ones)

romans.sort()
mOrder = romans.index("M")

order = {}

for i in range(0, 1000):
    order[romans[i]] = i

def main():
    n = int(input())
    for i in range(n):
        x = int(input())
        if (x > 1000):
            q = int(x / 1000)
            r = x % 1000

            i = order[val[r]] if r > 0 else -1
            if (i > mOrder):
                ord = (i - 1000) + q * (mOrder + 1 - 1000)
            else:
                ord = q * (mOrder + 1) + i + 1
            print(ord)
        else:
            roman = val[x]
            ord = order[roman]
            if (ord > mOrder):
                print(ord - 1000)
            else:
                print(ord + 1)

main()