from cs50 import get_int

height = get_int("Height: ")

for x in range(height):
    print((height-(x+1))*" " + (x+1)*"#")
