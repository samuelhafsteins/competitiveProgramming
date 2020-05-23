import sys

n = int(sys.stdin.readline())

for i in range(n):
    t, x = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    a = list(dict.fromkeys(a))
    a.sort()
    x -= a[0] - 1
    best = a[0]
    print(x)
    for i in range(1, len(a)):
        if a[i] - a[i-1] - 1 > x:
            break
        else:
            best = a[i]
            x -= a[i] - a[i-1] - 1
    
    print(best + x)



