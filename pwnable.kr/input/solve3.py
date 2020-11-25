from pwn import *
import os
import time

argvs = ["" for i in range(0,100)]
argvs[ord('A')] = '\x00'
argvs[ord('B')] = '\x20\x0a\x0d'

stderr,stderw = os.pipe()

p = process(executable = 'input', argv = argvs, stderr=stderr)

p.recvuntil("Stage 1 clear!\n")
print("Stage 1 clear!")

payload = b"\x00\x0a\x00\xff"

p.send(payload)
os.write(stderw, b"\x00\x0a\x02\xff")

p.recvuntil("Stage 2 clear!\n")

print("Stage 2 clear!")