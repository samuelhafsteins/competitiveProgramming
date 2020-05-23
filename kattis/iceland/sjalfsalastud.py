import sys

c, t, f, h = map(int, sys.stdin.readline().split())
ans = 0


while c > 0:
    if h:
        if h + f < c:
            h -= 1
            t -= 3
            f += 1
            c -= 1
            ans += 4
        else:
            #print 'h'
            h -= 1
            c -= 1
            t += 2
            ans += 1
    elif f <= c and f:
        #print '2f'
        f -= 1
        c -= 1
        t -= 3
        ans += 4
        #print ans
        #print c
    elif f:
        #print 'f'
        f -= 2
        c -= 1
        t += 2
        ans += 2
    else:
        #print 't'
        c -= 1
        t -= 8
        ans += 8

print ans
