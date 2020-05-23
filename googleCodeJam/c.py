import sys
from collections import deque

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    l = list()
    for i in range(n):
        a, b = map(int, sys.stdin.readline().split())
        l.append([a, b, i])
    l = sorted(l, key=lambda x: x[0])
    c = 0
    j = 0
    #print(l)
    ans = [0 for k in range(n)]
    for i in l:
        #print(c, j)
        if i[0] >= c:
            c = i[1]
            ans[i[2]] = "C"
        elif i[0] >= j:
            j = i[1]
            ans[i[2]] = "J"
        else:
            ans = ["IMPOSSIBLE"]
            break
    
    print "Case #" + str(_ + 1) + ": " + "".join(ans)