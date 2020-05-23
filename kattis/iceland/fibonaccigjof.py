import sys

mod = 10**9 + 7

mats = [[[0 for i in range(2)] for i in range(2)] for _ in range(35)]

fib = []
c = [0]

def matrixMult(a, b):
    res = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                res[i][j] += (a[i][k] * b[k][j]) % mod
            res[i][j] %= mod
    return res

def vecMult(mat, vec):
    res = [0, 0]
    for i in range(2):
        for k in range(2):
            res[i] += (mat[i][k] * vec[k]) % mod
        res[i] %= mod
    
    #print res[0]

    return res

def power(d):
    res = mats[0]

    #for i in bin(d)[2:]: print i

    for i in range(34):
        if (d>>i) & 1:
            res = matrixMult(res, mats[i+1])
    
    return res

def genMats():
    mats[0] = [[1, 0], [0, 1]]
    mats[1] = [[0, 1], [1, 1]]

    for e in range(2, 35):
        mats[e] = matrixMult(mats[e-1], mats[e-1])

class segmentTree:
    def __init__(self, n):
        self.n = n
        self.lo = [0 for i in range(4*n+1)]
        self.hi = [0 for i in range(4*n+1)]
        self.delta = [0 for i in range(4*n+1)]
        self.sum = [[0, 0] for i in range(4*n+1)]
        self.init(1, 0, n-1)

    def init(self, i, a, b):
        self.lo[i] = a
        self.hi[i] = b

        if a == b:
            self.sum[i][0] = vecMult(power(fib[c[0]]), [0, 1])[0]
            self.sum[i][1] = vecMult(power(fib[c[0]]), [0, 1])[1]
            #print self.sum[i][0], self.sum[i][1]
            c[0] += 1
            return
        
        m = (a+b-1)//2

        self.init(2*i, a, m)
        self.init(2*i+1, m+1, b)

        self.update(i)
    
    def prop(self, i):
        #print self.delta[i]
        self.delta[2*i] += self.delta[i]
        self.delta[2*i+1] += self.delta[i]
        self.delta[i] = 0

    def update(self, i):
        leftSum = vecMult(power(self.delta[2*i]), self.sum[2*i])
        rightSum = vecMult(power(self.delta[2*i+1]), self.sum[2*i+1])

        self.sum[i][0] = (leftSum[0] + rightSum[0]) % mod
        self.sum[i][1] = (leftSum[1] + rightSum[1]) % mod

    def add(self, i, a, b, val):
        if b < self.lo[i] or self.hi[i] < a:
            return
        if a <= self.lo[i] and self.hi[i] <= b:
            self.delta[i] += val
            return
        
        self.prop(i)

        self.add(2*i, a, b, val)
        self.add(2*i+1, a, b, val)

        self.update(i)
    
    def sumQuary(self, i, a, b):
        #print i
        if b < self.lo[i] or self.hi[i] < a:
            return 0
        if a <= self.lo[i] and self.hi[i] <= b:
            return vecMult(power(self.delta[i]), self.sum[i])[0] % mod
        
        self.prop(i)

        sum1 = self.sumQuary(2*i, a, b) % mod
        sum2 = self.sumQuary(2*i+1, a, b) % mod

        self.update(i)

        return (sum1 + sum2) % mod

n, m, t, l, r, d = 0, 0, 0, 0, 0, 0

n, m = map(int, sys.stdin.readline().split())

genMats()

fib = list(map(int, sys.stdin.readline().split()))

st = segmentTree(n)

for i in range(m):
    a = list(map(int, sys.stdin.readline().split()))
    if len(a) == 4:
        t, l, r, d = map(int, a)
        l -= 1
        r -= 1
        st.add(1, l, r, d)
    else:
        t, l, r = map(int, a)
        l -= 1
        r -= 1
        print st.sumQuary(1, l, r) % mod