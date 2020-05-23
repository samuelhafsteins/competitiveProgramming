import sys

L, R, A = [-1 for _ in range(1200)], [-1 for _ in range(1200)], [-1 for _ in range(1200)]
VIS = [0 for _ in range(6000)]
n, x = map(int, sys.stdin.readline().split())

def DFS(at):
    if VIS[at]: return
    VIS[at] = 1
    for i in range(n): 
        if L[i] <= at and at <= R[i]: DFS(at + A[i])

for i in range(n):
    L[i], R[i], A[i] = map(int, sys.stdin.readline().split())

DFS(x)
mx = x

for i in range(6000): 
    if VIS[i]: mx = i

print mx
