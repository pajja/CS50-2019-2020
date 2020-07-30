import cs50
import sys
import csv
from cs50 import SQL

db = SQL("sqlite:///students.db")

if len(sys.argv) != 2:
    print("Error. Invalid Input.")
    exit(1)

with open("characters.csv") as c:
    charact = csv.DictReader(c)
    for count, row in enumerate(charact):
        split = row["name"].split(" ")
        if len(split) == 2:
            db.execute(
            "INSERT INTO students (id, first, last, house, birth) VALUES (?,?,?,?,?)",
            count+1, split[0], split[1], row["house"], row["birth"])
        elif len(split) > 2:
            db.execute(
            "INSERT INTO students (id, first, middle, last, house, birth) VALUES (?,?,?,?,?,?)",
            count+1, split[0], split[1], split[2], row["house"], row["birth"])
        else:
            print("Error. Wrong file | Program went wrong")

c.commit()
c.close()
exit(0)
