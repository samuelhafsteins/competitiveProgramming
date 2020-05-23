import sys

a = list(sys.stdin.readline().rstrip())
ans = []

indx = 0

for i in a:
    if i == 'L': indx -= 1
    elif i == 'R': indx += 1
    elif i == 'B':
        indx -= 1
        del ans[indx]
    else:
        ans.insert(indx, i)
        indx += 1
    #print ans, indx
    
print ''.join(ans)