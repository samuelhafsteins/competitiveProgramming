import sys

n, k = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n)]

for i in range(n - 1):
    a, b, d = map(int, sys.stdin.readline().split())
    graph[a - 1].append((b - 1, d))
    graph[b - 1].append((a - 1, d))

print graph