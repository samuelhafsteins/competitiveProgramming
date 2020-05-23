import sys, bisect

n, m = map(int, sys.stdin.readline().split())

f, s = [], []

for _ in range(m):
    i, j = map(int, sys.stdin.readline().split())
    

sm = sum(a)
print sm
print "The Mexicans took our jobs! Sad!" if sm > n/2 else "The Mexicans are Lazy! Sad!"