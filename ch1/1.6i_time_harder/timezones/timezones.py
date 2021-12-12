from datetime import *

times = {
    "UTC": 0,
    "GMT": 0,
    "BST": 1,
    "IST": 1,
    "WET": 0,
    "WEST": 1,
    "CET": 1,
    "CEST": 2,
    "EET": 2,
    "EEST": 3,
    "MSK": 3,
    "MSD": 4,
    "AST": -4,
    "ADT": -3,
    "NST": -3.5,
    "NDT": -2.5,
    "EST": -5,
    "EDT": -4,
    "CST": -6,
    "CDT": -5,
    "MST": -7,
    "MDT": -6,
    "PST": -8,
    "PDT": -7,
    "HST": -10,
    "AKST": -9,
    "AKDT": -8,
    "AEST": 10,
    "AEDT": 11,
    "ACST": 9.5,
    "ACDT": 10.5,
    "AWST": 8
}

n = int(input())

for i in range(n):
    line = input().split(" ")
    if (line[0] == "noon"):
        t = datetime.strptime("12:00", "%H:%M")
        tfrom = line[1]
        tto = line[2]
    elif (line[0] == "midnight"):
        t = datetime.strptime("00:00", "%H:%M")
        tfrom = line[1]
        tto = line[2]
    else:
        p = "PM" if line[1] == "p.m." else "AM"
        t = datetime.strptime(line[0] + " " + p, "%I:%M %p")
        tfrom = line[2]
        tto = line[3]
    
    t = t - timedelta(hours=times[tfrom]) + timedelta(hours=times[tto])

    t = str(datetime.strftime(t, "%I:%M %p"))

    if (t == "12:00 AM"):
        print("midnight")
    elif (t == "12:00 PM"):
        print("noon")
    else:
        t = t.lstrip('0')
        t = t.replace("PM", "p.m.")
        t = t.replace("AM", "a.m.")

        print(t)