from datetime import datetime, timedelta

now = datetime.strptime(input(),"%H:%M:%S")
to = datetime.strptime(input(),"%H:%M:%S")

if (now == to):
    print("24:00:00")
else:
    if (to < now):
        to = to + timedelta(days=1)
    diff = to - now
    diff = datetime.strptime(str(diff), "%H:%M:%S")
    print(diff.time())