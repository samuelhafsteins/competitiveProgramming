import sys
from itertools import combinations_with_replacement
from collections import defaultdict, Counter

def findEmpty(arr, l):
  for r in range(n):
    for c in range(n):
      if arr[r][c] == 0:
        l[0]=r
        l[1]=c
        return True
  return False

def usedInRow(arr, r, num):
  if num in arr[r]:
    return True
  return False

def usedInCol(arr, c, num):
  for i in range(n):
    if arr[i][c] == num:
      return True
  return False

def checkLocation(arr, r, c, num):
  return not usedInRow(arr, r, num) and not usedInCol(arr, c, num)

def solve(arr):
  l = [0, 0]

  if not findEmpty(arr, l):
    return True

  r = l[0]
  c = l[1]

  for num in range(1,n+1):
    if checkLocation(arr, r, c, num):
      arr[r][c] = num

      if solve(arr):
        return True

      arr[r][c] = 0
  
  return False

for t in range(int(sys.stdin.readline())):
  n, k = map(int, sys.stdin.readline().split())

  dic = defaultdict(list)
  for i in combinations_with_replacement([i+1 for i in range(n)], n):
    dic[sum(i)].append(i)

  valid = False
  for i in dic[k]:
    c = Counter(i)
    if len(c) == 2:
      for j in c.values():
        valid = i
        if j == n-1:
          valid = False
          break
    else:
      valid = i
      break 

  if valid == False:
    print("Case #"+str(t+1)+": IMPOSSIBLE")
    continue
  
  print("Case #"+str(t+1)+": POSSIBLE")
  
  matrix = [[0 for i in range(n)] for i in range(n)]
  for i in range(n):
    matrix[i][i] = valid[i]

  if solve(matrix):
    for i in matrix:
      print(" ".join(map(str, i)))