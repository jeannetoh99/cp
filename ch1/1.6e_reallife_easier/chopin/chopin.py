import sys

altNotes = {
    'A#': 'Bb',
    'Bb': 'A#',
    'C#': 'Db',
    'Db': 'C#',
    'D#': 'Eb',
    'Eb': 'D#',
    'F#': 'Gb',
    'Gb': 'F#',
    'G#': 'Ab',
    'Ab': 'G#',
}

lines = sys.stdin.readlines()
size = len(lines)

for i in range(size):
    line = lines[i]
    line = line.strip().split(" ")
    note = line[0]
    tonality = line[1]

    if (note not in altNotes):
        print("Case %d:" % (i+1), "UNIQUE")
    else:
        print("Case %d:" % (i+1), altNotes[note], tonality)
