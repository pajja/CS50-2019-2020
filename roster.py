import cs50
from cs50 import SQL
import sys

db = SQL("sqlite:///students.db")

if len(sys.argv) != 2:
    print("Error. Invalid input.")
    exit(1)

housename = sys.argv[1].lower()
houses = ["gryffindor", "ravenclaw", "slytherin", "hufflepuff"]
if housename not in houses:
    print("Error. Invalid input.")
    exit(1)

query = db.execute(
    """SELECT first, middle, last, birth FROM students
    WHERE lower(house) = ? ORDER BY last, first;""", housename)

for row in query:
    print(row["first"], end = " ")
    if row["middle"] != None: print(row["middle"], end = " ")
    print(row["last"], end = ", born ")
    print(str(row["birth"]))

exit(0)
