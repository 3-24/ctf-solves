from Crypto.Util.number import long_to_bytes as l2b
from gmpy2 import powmod

def get_config():
    f = open("enc.txt",'r')
    n,s = map(int,f.readline().strip().replace('(','').replace(')','').replace(' ','').replace('L','').split(','))
    ct = int(f.readline().strip().replace('L',''))
    f.close()
    return n,s,ct,151

n,s,ct,e = get_config()


def coppersmith(shiftbits, k):
    F.<x> = PolynomialRing(Zmod(n))
    invE = inverse_mod(e, n)
    f = (s << shiftbits) + x + (k - 1) * invE   # make monic
    x0 = f.small_roots(X=2 ** shiftbits, beta=0.44, epsilon=1/32)
    return x0


for bits in (1023,1025):
    for k in range(1, e):
        print "Trying bits: {:d}, k: {:d}".format(bits, k)
        shiftbits = bits // 2 - bits // 10
        x0 = coppersmith(shiftbits,k)
        if len(x0) != 0:
            x = Integer(x0[0])
            print "Success, x:",  x
            dp = x + (s << shiftbits)
            print "dp", dp
            p = (e*dp - 1) // k+1
            if p != -1:
                q = n // p
                assert n == p * q
                print(p,q)
                phi = (p-1)*(q-1)
                d = inverse_mod(e,phi)
                print(l2b(pow(ct,d,n)))
