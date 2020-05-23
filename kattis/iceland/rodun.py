import sys
from collections import defaultdict

d = defaultdict(list)

n, k = map(int, sys.stdin.readline().split())

sys.stdin.readline()

for _ in range(k):
    a, t, b = sys.stdin.readline().split()
    if t == '>':
        d[a].append(b)
    else: 
        d[b].append(a)

print d
