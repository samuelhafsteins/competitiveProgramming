import sys

t = int(sys.stdin.readline())


for _ in range(t):
    a = list()
    n = int(sys.stdin.readline())
    for i in range(n):
        a.append(list(map(int, sys.stdin.readline().split())))
    k, r, c = 0, 0, 0
    for i in range(n):
        if len(a[i]) != len(set(a[i])):
            r += 1
        k += a[i][i]
        temp = set()
        for j in range(n):
            temp.add(a[j][i])
        if len(temp) < n:
            c += 1
    print "Case #" + str(_ + 1) + ":", k, r, c

