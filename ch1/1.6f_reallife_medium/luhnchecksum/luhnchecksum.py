import math

T = input()

while True:
    try:
        n = input()
        digits = [int(char) for char in n]
        sum = 0
        for i in range(len(digits)):
            j = len(digits) - i - 1
            if (i % 2 == 0):
                sum += digits[j]
            else:
                k = 2 * digits[j]
                if (k > 9):
                    k = math.floor(k / 10) + k % 10
                sum += k
        if (sum % 10 == 0): print("PASS")
        else: print("FAIL")
    except EOFError:
        break
