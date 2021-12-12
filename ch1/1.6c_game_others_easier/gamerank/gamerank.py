import sys

games = sys.stdin.readline().strip()
games = [char for char in games]

rank = 25
stars = 0
cwins = 0

for game in games:
    if game == 'W':
        stars += 1
        cwins += 1
        if rank >= 6 and rank <= 25 and cwins >= 3:
            stars += 1
    else:
        cwins = 0
        if (rank > 0 and rank < 20) or (rank == 20 and stars > 0):
            stars -= 1
    
    if (rank <= 10 and stars > 5):
        rank -= 1
        stars = stars - 5
    elif (rank > 10 and rank <= 15 and stars > 4):
        rank -= 1
        stars = stars - 4
    elif (rank > 15 and rank <= 20 and stars > 3):
        rank -= 1
        stars = stars - 3
    elif (rank > 20 and rank <= 25 and stars > 2):
        rank -= 1
        stars = stars - 2
    elif (rank < 10 and stars < 0):
        rank += 1
        stars = 4
    elif (rank < 15 and stars < 0):
        rank += 1
        stars = 3
    elif (rank < 20 and stars < 0):
        rank += 1
        stars = 2
    if (rank <= 0):
        break

if (rank <= 0):
    print("Legend")
else:
    print(rank)