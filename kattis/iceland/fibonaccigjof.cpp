#pragma GCC optimize("Ofast","unroll-loops")
#pragma GCC target("avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ull> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
#define pb push_back
#define fs first
#define sc second

const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }
#define mod 1000000007

vvvll mats(40, vvll(2, vll(2)));
vll fib;
ll c = 0;
//vll fib;

vvll matrixMult(vvll a, vvll b){
    vvll res(2, vll(2));
    rep(i, 0, 2){
        rep(j, 0, 2){
            rep(k, 0, 2){
                res[i][j] += (a[i][k] * b[k][j]) % mod;
            }
            res[i][j] %= mod;
        }
    }
    return res; //skoða
}

vll vecMult(vvll mat, vll vec){
    vll res(2);
    rep(i, 0, 2){
        rep(k, 0, 2){
            res[i] += (mat[i][k] * vec[k]) % mod;
        }
        res[i] %= mod;
    }

    //cout << res[0] << endl;

    return res; //skoða
}

vvll power(ull d){

    vvll res = mats[0];

    rep(i, 0, 39){
        if((d >> i) & 1){
            res = matrixMult(res, mats[i+1]);
        }
    }

    return res;
}

void genMats(){
    mats[0][0][0] = mats[0][1][1] = 1;
    mats[0][0][1] = mats[0][1][0] = 0;
    mats[1][0][1] = mats[1][1][1] = mats[1][1][0] = 1;
    mats[1][0][0] = 0;
    for(int e=2; e < 40; e++){
        mats[e] = matrixMult(mats[e-1], mats[e-1]);
    }
}

class segmentTree{
    public:
        ull n;
        vll lo, hi, delta;
        vvll sum;

    segmentTree(ull n){
        this-> n = n;
        lo.resize(4*n+1);
        hi.resize(4*n+1);
        delta.resize(4*n+1);
        sum.resize(4*n+1, vll(2));
        init(1, 0, n-1);
    }

    void init(ull i, ull a, ull b){
        lo[i] = a;
        hi[i] = b;

        if (a == b){
            sum[i][0] = vecMult(power(fib[c]), {0, 1})[0];
            sum[i][1] = vecMult(power(fib[c]), {0, 1})[1];
            //cout << sum[i][0] << ' ' << sum[i][1] << endl;
            c++;
            return;
        }

        ll m = (a+b-1)/2;
        init(2*i, a, m);
        init(2*i+1, m+1, b);

        update(i);
    }

    void prop(ull i){
        //cout << delta[i] << endl;
        delta[2*i] += delta[i];
        delta[2*i+1] += delta[i];
        delta[i] = 0;
        //update(i);
    }

    void update(ull i){
        vll leftSum = vecMult(power(delta[2*i]), sum[2*i]);
        vll rightSum = vecMult(power(delta[2*i+1]), sum[2*i+1]); 

        sum[i][0] = (leftSum[0] + rightSum[0]) % mod;
        sum[i][1] = (leftSum[1] + rightSum[1]) % mod;
    }

    void add(ull i, ull a, ull b, ull val){
        if (b < lo[i] || hi[i] < a)
            return;
        if (a <= lo[i] && hi[i] <= b){
            //cout << i << endl;
            delta[i] += val;
            return;
        }

        prop(i);

        add(2*i, a, b, val);
        add(2*i+1, a, b, val);

        update(i);
    }

    ull sumQuary(ull i, ull a, ull b){
        //cout << i << endl;
        if (b < lo[i] || hi[i] < a)
            return 0;
        if (a <= lo[i] && hi[i] <= b){
            return vecMult(power(delta[i]), sum[i])[0] % mod;
        }

        prop(i);

        ull sum1 = sumQuary(2*i, a, b) % mod;
        ull sum2 = sumQuary(2*i+1, a, b) % mod;

        update(i);

        return (sum1 + sum2) % mod;
    }

};

int main(){
    ull n, m, t, l, r, d;
    cin >> n >> m;
    genMats();
    fib.resize(n);
    rep(i, 0, n) cin >> fib[i];
    segmentTree st(n);
    rep(i, 0, m){
        cin >> t >> l >> r;
        l -= 1, r -= 1;
        if (t == 1){
            cin >> d;
            st.add(1, l, r, d);
        }
        else{
            cout << st.sumQuary(1, l, r) % mod << '\n';
        }
    }
    return 0;
}