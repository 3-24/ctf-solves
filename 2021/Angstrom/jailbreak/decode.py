import struct

f1 = open("./data/arr1.hex", "r")
s1 = f1.read().replace("\n"," ").split()
arr1 = [None for _ in range (len(s1) // 4)]
for i in range (0,len(s1),4):
    subs1 = bytes.fromhex(s1[i] + s1[i+1] + s1[i+2] + s1[i+3])
    arr1[i//4] = struct.unpack("<L", subs1)[0]
f1.close()


f2 = open("./data/arr2.hex", "r")
s2 = f2.read().replace("\n"," ").split()
arr2 = [None for _ in range (len(s2))]
for i in range (0,len(s2)):
    arr2[i] = int(s2[i],16)
f2.close()

n = int(input())
v1 = arr1[n]
v2 = arr1[n+1] - v1
v3 = [None for _ in range (v2+1)]
v3[v2] = 0
if (v2 > 0):
    v5 = n
    v6 = 0
    while True:
        v7 = v5 ^ arr2[v1+v6]
        v3[v6] = v7
        v6 += 1
        v5 = (v5 * v7 + 17*n) % 256
        if (v2 == v6): break
print(''.join(map(chr, v3)))