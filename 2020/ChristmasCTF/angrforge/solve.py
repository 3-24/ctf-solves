import pwn

payload = ['A']*56
flag = b''

for i in range(56):
    instr_count = []
    for ch in range(0x20, 0x7F):
        payload[i] = chr(ch)
        p = pwn.process(['valgrind', '--tool=callgrind', '--callgrind-out-file=/dev/null',
                         '--log-file=callgrind.out', './angrforge'],)

        p.recvuntil('If you call my friend, I will give you a good reward.\n')
        p.sendline(''.join(payload))

        p.poll(block=True)
        p.close()
        with open('./callgrind.out', 'r') as f:
            callgrind = f.read()

        j = callgrind.find('Collected : ')
        print(int(callgrind[j+12:j+18]))
        instr_count.append(int(callgrind[j+12:j+18]))

    ch = instr_count.index(max(instr_count)) + 0x20
    payload[i] = chr(ch)
    flag += bytes([ch])
    print(flag)
