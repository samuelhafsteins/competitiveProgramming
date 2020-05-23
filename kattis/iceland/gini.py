import sys

n = int(sys.stdin.readline())

y = [int(sys.stdin.readline()) for _ in range(n)]

y = sorted(y)
sm = y[-1] * n
smList = sum(y)
ans = 0
for i in range(n-1, -1, -1):
    ans += sm - (smList + y[i] * n - sm)
    #print ans
    sm -= (y[i] - y[i-1]) * i

print(ans/(2.0*n*smList))