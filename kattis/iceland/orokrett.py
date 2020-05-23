import sys
from collections import defaultdict
a = list(map(lambda s: s.strip(), sys.stdin.readline().rstrip().split("EDA")))

for i in a:
    d = defaultdict(list)
    temp = list(i[1:-1].split(" OG "))
    #print temp
    for j in temp:
        if j[0] == '!':
            j = j[1:]
            if len(d[j]) == 0: d[j].append(False)
            else: 
                if d[j][0] == True: break
        else:
            if len(d[j]) == 0: d[j].append(True)
            else:
                if d[j][0] == False: break
    else:
        print 'Jebb'
        exit(0)

print 'Neibb'