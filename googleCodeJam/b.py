import sys

n = int(sys.stdin.readline())

for _ in range(n):
    ans = ""
    s = list(map(int, sys.stdin.readline().rstrip()))
    prev = 0
    for i in s:
        if i > prev:
            ans += "(" * (i - prev)
        elif i < prev:
            ans += ")" * (prev - i)
        prev = i
        ans += str(i)
    
    ans += ")" * prev
    print "Case #" + str(_ + 1) + ":", ans