
while True:
    try:
        domain = input()
        domain = domain[7:].strip().split(" ")
        codomain = input()
        codomain = codomain[9:].strip().split(" ")
        n = int(input())
        atob = {}
        btoa = {}
        tob = set()
        
        res = ''
        
        notFunction = False
        injective = True
        surjective = False

        for i in range(n):
            [a, b] = input().strip().split(" -> ")
            if (res != ''): continue
            if (a in atob.keys()): notFunction = True
            atob[a] = b
            if (b in btoa.keys()): injective = False
            btoa[b] = a
            tob.add(b)
        
        surjective = len(tob) == len(codomain)

        if (notFunction):
            print("not a function")
        elif (surjective and injective):
            print("bijective")
        elif (surjective):
            print("surjective")
        elif (injective):
            print("injective")
        else:
            print("neither injective nor surjective")

    except EOFError:
        break