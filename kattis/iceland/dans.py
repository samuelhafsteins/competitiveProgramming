import sys
from collections import defaultdict


n,k = map(int, sys.stdin.readline().split())

a = list(map(int, sys.stdin.readline().split()))
b = sorted(a)
d = defaultdict(int)
ans = ['' for _ in range(n)]


circle = []
for i in range(n):
    d[a[i] - 1] = i - (a[i] - 1)

for i in d:
    temp = d[i] + i
    c = 1
    #print temp
    while True:
        temp += d[temp]
        c += 1
        if temp == i: break
    circle.append(c)

for i in b:
    if k != 1: h = k % circle[i - 1]
    else: h = 1
    #print h
    t = i - 1
    for _ in range(h):
        t += d[t]
    ans[t] = i
print ' '.join(map(str, ans))
#print a, d, circle, b