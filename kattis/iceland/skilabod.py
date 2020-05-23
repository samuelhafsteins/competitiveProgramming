import sys
N = int(sys.stdin.readline().strip())
lengd = []
for i in range(N):
    x, y = map(int , sys.stdin.readline().strip().split())
    lengd.append((x*x)+(y*y))

lengd = sorted(lengd)
Q = int(sys.stdin.readline().strip())

for i in range(Q):
    r = int(sys.stdin.readline().strip())
    r *= r
    mn = 0
    mx = N-1
    result = 0
    while mn <= mx:
        mid = (mx+mn) // 2
        if lengd[mid] <= r:
            result = mid+1
            mn = mid+1
        else:
            mx = mid-1
    print(result)