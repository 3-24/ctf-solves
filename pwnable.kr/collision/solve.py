from pwn import *

payload1 = p32(0x6c5cecc)
payload2 = p32(0x6c5cec8)

payload = (payload1 + payload2*4)

sh = ssh('col', 'pwnable.kr', password='guest', port=2222)
p = sh.process(['./col',payload])
p.interactive()