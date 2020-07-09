from cs50 import get_float

owed = 0 ;

while not owed > 0:
    owed = get_float("Cash owed: ")

change = [0.25, 0.1, 0.05, 0.01]
x = 0
unit = 0

while owed > 0:
    while owed >= change[x]:
        owed -= change[x]
        owed = round(owed, 2)
        unit +=1
    else:
        x += 1
        continue

print(unit)
