import sys

n, q = map(int, sys.stdin.readline().split())

a = [0 for _ in range(n)]

up = 0
d = n
inv = False

for i in range(q):
    inp = list(map(int, sys.stdin.readline().split()))
    if inp[0] == 1:
        if a[inp[1] - 1] == 0:
            up += 1
            d -= 1
            a[inp[1] - 1] = 1
        else:
            up -= 1
            d += 1
            a[inp[1] - 1] = 0
    elif inp[0] == 2:
        if inv: inv = False
        else: inv = True
    elif inp[0] == 3:
        if inv: print n - up
        else: print up
    else:
        c = 0
        #print a
        for i in range(inp[1] - 1, inp[2]):
            #print a[i], 'list'
            if a[i] == 1:
                c += 1
        #print c, 'hi'
        if inv: print inp[2] - inp[1] + 1 - c
        else: print c
