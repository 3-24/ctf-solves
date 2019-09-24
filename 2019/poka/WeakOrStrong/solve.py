from gmpy2 import *
from Crypto.Util.number import long_to_bytes as l2b

f = open('enc.txt','r')
f.readline()
N,c = map(int, f.readline().strip().replace('L','').replace('(','').replace(')','').replace(' ','').split(','))

p = 96519019965985189420318021978086209355220104728842768493515285964382881562961
q = 69517189020993799354976567194165615733741804094602331588109289689403844859157
e = 65537


assert N == p * q

d = powmod(e,-1,(p-1)*(q-1))

m = powmod(c,d,N)

print(l2b(m))
