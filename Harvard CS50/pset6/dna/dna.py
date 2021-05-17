import sys
import csv

if len(sys.argv)!=3:
    print(f"error")
    exit(0)
sequences = open(f"{sys.argv[2]}", "r")
for line in sequences:
    nTATC=0
    nAGATC=0
    nAATG=0
    nGAAA=0
    nTCTG=0
    nGATA=0
    nTTTTTTCT=0
    nTCTAG=0
    i=0
    while i+4 <= len(line):
        if line[i:i+4] == 'AATG':
            n=0
            while line[i:i+4] == 'AATG':
                n+=1
                if n>nAATG:
                    nAATG = n
                i+=4
            i-=3
        elif line[i:i+4] == 'TATC':
            n=0
            while line[i:i+4] == 'TATC':
                n+=1
                if n>nTATC:
                    nTATC = n
                i+=4
            i-=3
        elif line[i:i+5] == 'AGATC':
            n=0
            while line[i:i+5] == 'AGATC':
                n+=1
                if n>nAGATC:
                    nAGATC = n
                i+=5
            i-=4
        elif line[i:i+4] == 'GAAA':
            n=0
            while line[i:i+4] == 'GAAA':
                n+=1
                if n>nGAAA:
                    nGAAA = n
                i+=4
            i-=3
        elif line[i:i+4] == 'TCTG':
            n=0
            while line[i:i+4] == 'TCTG':
                n+=1
                if n>nTCTG:
                    nTCTG = n
                i+=4
            i-=3
        elif line[i:i+4] == 'GATA':
            n=0
            while line[i:i+4] == 'GATA':
                n+=1
                if n>nGATA:
                    nGATA = n
                i+=4
            i-=3
        elif line[i:i+8] == 'TTTTTTCT':
            n=0
            while line[i:i+8] == 'TTTTTTCT':
                n+=1
                if n>nTTTTTTCT:
                    nTTTTTTCT = n
                i+=8
            i-=7
        elif line[i:i+5] == 'TCTAG':
            n=0
            while line[i:i+5] == 'TCTAG':
                n+=1
                if n>nTCTAG:
                    nTCTAG = n
                i+=5
            i-=4
        else:
            i=i+1
sequences.close()
with open(f"{sys.argv[1]}") as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        i=len(row)-1
        if 'AGATC' in row and int(row['AGATC'])==nAGATC:
            i-=1
        if 'TATC' in row and int(row['TATC'])==nTATC:
            i-=1
        if 'AATG' in row and int(row['AATG'])==nAATG:
            i-=1
        if 'GAAA' in row and int(row['GAAA'])==nGAAA:
            i-=1
        if 'TCTG' in row and int(row['TCTG'])==nTCTG:
            i-=1
        if 'GATA' in row and int(row['GATA'])==nGATA:
            i-=1
        if 'TTTTTTCT' in row and int(row['TTTTTTCT'])==nTTTTTTCT:
            i-=1
        if 'TCTAG' in row and int(row['TCTAG'])==nTCTAG:
            i-=1
        if i==0:
            print(f"{row['name']}")
            exit(0)
print(f"No match")
