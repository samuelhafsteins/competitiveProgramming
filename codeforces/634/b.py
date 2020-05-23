import sys, string

alp = string.ascii_lowercase

for _ in range(int(sys.stdin.readline())):
    n, a, b = map(int ,sys.stdin.readline().split())

    l = alp[0:b]
    #print l
    ans = ''
    while n:
        for i in range(b):
            ans += l[i]
            n -= 1
            if n == 0:
                break
            

    print ans

