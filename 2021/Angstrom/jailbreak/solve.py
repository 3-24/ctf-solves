from pwn import *

p = remote("shell.actf.co", 21701)

context.log_level = 'DEBUG'

def send_input(s):
    p.recvuntil("What would you like to do?\n")
    p.sendline(s)

def break_number(n):
    def _break_number(x, L):    # L is list such that False corresponds to red button, True then green button
        if (x == 1):
            L.reverse()
            return L
        elif (x % 2 == 0):
            L.append(False)
            return _break_number(x // 2, L.copy())
        else:
            L.append(True)
            return _break_number(x // 2, L.copy())
    return _break_number(n, [])

send_input("look around")
send_input("pick the snake up")
send_input("throw the snake at kmh")
send_input("pry the bars open")

send_input("look around")
arr = break_number(1337)
for b in arr:
    if b:
        send_input("press the green button")
    else:
        send_input("press the red button")

send_input("bananarama")
p.interactive()         #   actf{guess_kmh_still_has_unintended_solutions}