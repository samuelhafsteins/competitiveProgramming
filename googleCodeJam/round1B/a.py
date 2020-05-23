import sys

def subArraySum(arr, n, sum): 
      
    # Pick a starting  
    # point 
    for i in range(n): 
        curr_sum = arr[i] 
      
        # try all subarrays 
        # starting with 'i' 
        j = i+1
        while j <= n: 
          
            if curr_sum == sum: 
                #print ("Sum found between") 
                #print("indexes %d and %d"%( i, j-1)) 
                  
                return arr[i:j]
                  
            if curr_sum > sum or j == n: 
                break
              
            curr_sum = curr_sum + arr[j] 
            j += 1
  
    #print ("No subarray found") 
    return []

n = int(sys.stdin.readline())
#print n

arr = [2**i for i in range(32)]

for t in range(n):
    t1 = False
    t2 = False
    direct = []
    a, b = map(int, sys.stdin.readline().split())
    ans = list()
    
    if a > 0: direct.append('E')
    elif a < 0: direct.append('W')
    if b > 0: direct.append('N')
    elif b < 0: direct.append('S')

    A = subArraySum(arr, 32, abs(a))
    B = subArraySum(arr, 32, abs(b))

    if a % 2 == 0 and b % 2 == 0 or a % 2 == 1 and b % 2 ==1:
        print 'Case #' + str(t + 1) + ': IMPOSSIBLE'
        continue
    elif a % 2 == 1:
        C = subArraySum(arr[1:], len(arr[1:]), abs(a) + 1)
        AB = A + B
        BC = B + C + [1]

        AB.sort()
        BC.sort()

        print direct
        for i in range(len(AB)):
            if AB[i] != 2**i:
                t1 = True
                break
        for i in range(len(BC)):
            if BC[i] != 2**i:
                t2 = True
                break
        if t1 and t2:
            print 'Case #' + str(t + 1) + ': IMPOSSIBLE'
            continue
        elif not t1:
            print AB
        else:
            print BC
    else:     
        C = subArraySum(arr[1:], len(arr[1:]), abs(b) + 1)
        AB = A + B
        AC = A + C + [1]

        AB.sort()
        AC.sort()
        
        print direct
        for i in range(len(AB)):
            if AB[i] != 2**i:
                t1 = True
                break
        for i in range(len(AC)):
            if AC[i] != 2**i:
                t2 = True
                break
        if t1 and t2:
            print 'Case #' + str(t + 1) + ': IMPOSSIBLE'
            continue
        elif not t1:
            print AB
        else:
            print AC