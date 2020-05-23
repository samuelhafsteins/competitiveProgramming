import sys
from collections import deque
def maxSubArraySum(a,size): 
       
    max_so_far = -sys.maxint - 1
    max_ending_here = 0
       
    for i in range(0, size): 
        max_ending_here = max_ending_here + a[i] 
        if (max_so_far < max_ending_here): 
            max_so_far = max_ending_here 
  
        if max_ending_here < 0: 
            max_ending_here = 0   
    return max_so_far 

n = int(sys.stdin.readline())

a = list(map(int, sys.stdin.readline().split()))

smList = []

sm = 0
i = 0
while True:
    try:
        while a[i] != 1:
            sm += 1
            i += 1
        smList.append(sm)
        sm = 0

        while a[i] != 0:
            sm -= 1
            i += 1
        smList.append(sm)
        sm = 0
    except:
        break
if sm > 0:  
    smList.append(sm)
if smList[0] == 0: del smList[0:2]
c = 0
for i in a:
    if i == 1:
        c += 1

if smList: print c + maxSubArraySum(smList, len(smList))
else: print n - 1