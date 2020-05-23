//#pragma GCC optimize("Ofast","unroll-loops")
//#pragma GCC target("avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
#define pb push_back
#define fs first
#define sc second

const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }
#define mod 1000000007

class segmentTree{
    public:
        int n;
        vi lo, hi, mn, delta;

    segmentTree(int n){
        this->n = n;
        lo.resize(4*n+1);
        hi.resize(4*n+1);
        delta.resize(4*n+1);
        mn.resize(4*n+1);
        init(1, 0, n-1);
    }

    void init(int i, int a, int b){
        lo[i] = a;
        hi[i] = b;
        if (a == b)
            return;
        int m = (a+b-1)/2;
        init(2*i, a, m);
        init(2*i+1, m+1, b);
    }

    void prop(int i){
        delta[2*i] += delta[i];
        delta[2*i+1] += delta[i];
        delta[i] = 0;
    }

    void update(int i){
        mn[i] = min(mn[2*i] + delta[2*i], mn[2*i+1] + delta[2*i+1]);
    }

    void add(int i, int a, int b, int val){
        if (b < lo[i] || hi[i] < a)
            return;
        if (a <= lo[i] && hi[i] <= b){
            delta[i] += val;
            return;
        }

        prop(i);

        add(2*i, a, b, val);
        add(2*i+1, a, b, val);

        update(i);
    }

    int minimum(int i, int a, int b){
        if (b < lo[i] || hi[i] < a)
            return INT_MAX;
        if (a <= lo[i] && hi[i] <= b){
            return mn[i] + delta[i];
        }

        prop(i);

        int minLeft = minimum(2*i, a, b);
        int minRight = minimum(2*i+1, a, b);

        update(i);

        return min(minLeft, minRight);
    }

};

int main(){
    int n, m, l, r, d, t;
    cin >> n >> m;
    segmentTree st(n);
    rep(i, 0, m){
        cin >> t >> l >> r;
        if (t == 1){
            cin >> d;
            st.add(1, l, r, d);
        }
        else{
            cout << st.minimum(1, l, r) << endl;
        }
    }
    return 0;
}