import sys
from collections import defaultdict

#print "hi"
n = int(sys.stdin.readline())

nrs = defaultdict(int)

for i in range(n):
    nr = sys.stdin.readline().rstrip()
    for x in range (1, 8):
        nrs[nr[0:x]] += 1

#print nrs
q = int(sys.stdin.readline())

for i in range(q):
    sys.stdout.write(str(nrs[sys.stdin.readline().rstrip()]) + '\n')