import sys

n, m, k = map(int, sys.stdin.readline().split())

a = list(map(int, sys.stdin.readline().split()))
b = list(map(int, sys.stdin.readline().split()))

wins = []
if a[0] > b[0]: w = 1
else: w = 0
e = 0
best = 0

for i in range(1, n):
    if a[i] + k > b[i] and m > 0:
        w += 1
    elif a[i] > b[i]:
        w += 1
    else:
        e += 1
    m -= 1

if w > e: print 0
else: print "Neibb"

1 3

3 2 2
2 4 4

2 3 2
4 2 4