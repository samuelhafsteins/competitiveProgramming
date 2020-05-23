from collections import defaultdict
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
d = defaultdict(list)

for i in strs:
    d[''.join(list(sorted(i)))].append(i)
a = []
for i in d:
     a.append(d[i])
print a