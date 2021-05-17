from cs50 import get_string
import sys

text = get_string("Text: ")
str.split(text)
averagesofs=0
averagesofl=0
sentences=0
i=0
sa=0
la=0
x=0
y=0
letters=0
nwords = len(str.split(text))
while i < nwords :
    j=0
    m = len(str.split(text)[i])
    while j < m:
        if str.split(text)[i][j]==".":
            sentences+=1
        if str.split(text)[i][j]=="?":
            sentences+=1
        if str.split(text)[i][j]=="!":
            sentences+=1
        if str.split(text)[i][j].isalpha():
            letters += 1
        j+=1
    i+=1
k=100/nwords
averagesofl = (letters*k)
averagesofs = (sentences*k)
Grade = round(0.0588 * (averagesofl) - 0.296 * (averagesofs) - 15.8)
if Grade<1:
    print(f"Before Grade 1")
if Grade>=1 and Grade<=16:
    print(f"Grade {Grade}")
if Grade > 16:
    print(f"Grade 16+")