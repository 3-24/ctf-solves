from Crypto.Cipher import Blowfish
import base64

def dec_blowfish(cp, key):
    cipher = Blowfish.new(key, Blowfish.MODE_ECB)
    msg = cipher.decrypt(cp)
    return msg

def enc_blowfish(cp, key):
    cipher =  Blowfish.new(key, Blowfish.MODE_ECB)
    msg = cipher.encrypt(cp)
    return msg

#plain = base64.b64decode("QUJDREVGR0g=".encode('ascii'))
#cipher = base64.b64decode("J8LFHyoEuoo=".encode('ascii'))
plain = base64.b64decode("MTIzNDU2Nzg=".encode('ascii'))
cipher = base64.b64decode("BO9qLlWi45U=".encode('ascii'))

C1set = set([])
C1dict = {}
D2set = set([])
D2dict = {}

for i in range (0x100):
    for j in range (0x100):
        key1 = bytes([0x9e, 0x91, 0x9b, 0xb3, 0x3a, 0xef, i, j])
        r = enc_blowfish(plain, key1)
        C1set.add(r)
        C1dict[r] = key1

for k in range (0x100):
    for l in range (0x100):
        key2 = bytes([k, l, 0xf6, 0xea, 0x6d, 0x93, 0x7f, 0x22])
        r = dec_blowfish(cipher, key2)
        D2set.add(r)
        D2dict[r] = key2

common = (C1set & D2set).pop()
key1 = C1dict[common]
key2 = D2dict[common]

password = base64.b64decode("m6US+8OA+WK1Dl2kLc60Kxp2o3ydWPuXbZK2vBOrQEPTSzH6Od6Qn137Ctn7oLqm7Nb2uvb2wHU=".encode('ascii'))
D2 = dec_blowfish(password, key2)
D1 = dec_blowfish(D2, key1)
print(D1)