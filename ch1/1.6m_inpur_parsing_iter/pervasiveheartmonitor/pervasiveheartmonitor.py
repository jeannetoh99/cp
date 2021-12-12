import sys

for line in sys.stdin.readlines():
    line = line.strip().split(" ")
    if (line[0].isalpha()):
        numIndex = 0
        while (line[numIndex].isalpha()): numIndex += 1
        readings = [float(r) for r in line[numIndex:]]
        avg = sum(readings) / len(readings)
        name = " ".join(line[0:numIndex])
        print(avg, name)
    else:
        nameIndex = 0
        while (not line[nameIndex].isalpha()):
            nameIndex += 1
        readings = [float(r) for r in line[:nameIndex]]
        avg = sum(readings) / len(readings)
        name = " ".join(line[nameIndex:])
        print(avg, name)