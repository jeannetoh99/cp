mapping = {
    '1' : "    +    |    |    +    |    |    +",
    '2' : "+---+    |    |+---+|    |    +---+",
    '3' : "+---+    |    |+---+    |    |+---+",
    '4' : "+   +|   ||   |+---+    |    |    +",
    '5' : "+---+|    |    +---+    |    |+---+",
    '6' : "+---+|    |    +---+|   ||   |+---+",
    '7' : "+---+    |    |    +    |    |    +",
    '8' : "+---+|   ||   |+---+|   ||   |+---+",
    '9' : "+---+|   ||   |+---+    |    |+---+",
    '0' : "+---+|   ||   |+   +|   ||   |+---+",
    ':' : "  o o  ",

}

while True:
    line = input()
    if (line == "end"): 
        print("end")
        break

    for r in range(7):
        row = ""
        for c in range(5):
            if (c != 0): row += "  "
            if (c != 2): row += mapping[line[c]][r*5:r*5+5]
            else: row += mapping[line[c]][r]
        print(row)
    print("\n")

