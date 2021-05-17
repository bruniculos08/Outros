from cs50 import get_int
h=0
while h<1 or h>8:
    h = get_int("Height: ")
i=0
while i<h:
    i = i+1
    z = h
    while z>i:
        print(" ", end="")
        z = z-1
    j=0
    while j<i:
        print("#", end="")
        j=j+1
    print()
