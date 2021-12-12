from itertools import permutations

ones = {
    "I": 1,
    "II": 2,
    "III": 3,
    "IV": 4,
    "V": 5,
    "VI": 6,
    "VII": 7,
    "VIII": 8,
    "IX": 9,
}

tens = {
    "X": 10,
    "XX": 20,
    "XXX": 30,
    "XL": 40,
    "L": 50,
    "LX": 60,
    "LXX": 70,
    "LXXX": 80,
    "XC": 90
}

def main():
    line = input()
    perms = [''.join(p) for p in permutations(line)]
    num = 100
    roman = ""
    for p in perms:
        try:
            ip = p.find("I")
            vp = p.find("V")
            if (ip == -1 and vp == -1):
                onesp = -1
            elif (ip == -1):
                onesp = vp
            elif(vp == -1):
                onesp = ip 
            else:
                onesp = min(ip, vp)
            if (onesp == 0):
                sum = ones[p]
            elif (onesp == -1):
                sum = tens[p]
            else:
                ten = tens[p[0:onesp]]
                one = ones[p[onesp:]]
                sum = ten + one
            if (sum < num):
                num = sum
                roman = p
        except KeyError:
            continue
    print(roman)

main()