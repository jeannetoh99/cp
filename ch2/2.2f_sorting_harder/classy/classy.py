def solve(people):
    longest = 0

    for p in people:
        longest = max(longest, len(p['class']))

    for p in people:
        p['class'] += ("2"*(longest-len(p['class'])))
    
    people.sort(key=lambda x: (x['class'], x['name']))
    print("\n".join([p['name'] for p in people]))


def main():
    t = int(input())

    for i in range(t):
        n = int(input())
        people = list()
        for j in range(n):
            person = input().strip()
            [name, sclass] = person.split(": ")
            sclass = sclass[:-6]
            sclass = sclass.replace("upper", "1")
            sclass = sclass.replace("middle", "2")
            sclass = sclass.replace("lower", "3")
            sclass = sclass.replace("-", "")
            sclass = sclass[::-1]
            people.append({'name': name, 'class': sclass})
        solve(people)
        print('='*30)
    
main()