from operator import xor
import sys 
  
# Function to return the XOR of elements 
# from the range [1, n] 
def findXOR(n): 
    mod = n % 4; 
  
    # If n is a multiple of 4 
    if (mod == 0): 
        return n; 
  
    # If n % 4 gives remainder 1 
    elif (mod == 1): 
        return 1; 
  
    # If n % 4 gives remainder 2 
    elif (mod == 2): 
        return n + 1; 
  
    # If n % 4 gives remainder 3 
    elif (mod == 3): 
        return 0; 
  
# Function to return the XOR of elements 
# from the range [l, r] 
def findXORFun(l, r): 
    return (xor(findXOR(l - 1) , findXOR(r))); 
  
# Driver code 
n = int(sys.stdin.readline())
l, r = map(int, sys.stdin.readline().split())

ans = findXORFun(l, r)

if ans == 0: print "Enginn"
elif ans <= n: print ans
else: print "Gunnar"
 