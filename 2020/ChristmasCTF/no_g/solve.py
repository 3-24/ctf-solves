f = open('sheet.txt','r')

m = {"도":12, "레":13, "미":14, "파":15, "시":11, "라":10, "드":12, "리":13}

for line in f.readlines():
    l = line.strip()
    s = 0
    for c in l:
        s += m[c]
    
    print(chr(s),end='')