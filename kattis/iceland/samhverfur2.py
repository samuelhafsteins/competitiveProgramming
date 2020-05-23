def check (num):
    if len(num) % 2 == 0:
        n = num[0:len(num)/2]
        t = n + n[::-1]
        if int(t) < int(num): return t
        else:
            n = str(int(n) - 1)
            t = n + n[::-1]
            return t
        #print n, num, t
    else:
        n = num[0:len(num)/2]
        mid = num[len(num)/2]
        t = n + mid + n[::-1]
        if int(t) < int(num): return t
        else:
            if int(mid) > 0: t = n + str(int(mid)-1) + n[::-1]
            else:
                n = str(int(n) - 1)
                t = n + '9' + n[::-1]
            return t

print 1, 2
print 2, 4
print 3, 8
for i in range(4, 101):
    print i, check(str(2**i))