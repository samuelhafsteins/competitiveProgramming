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

int main(){
    int n;
    cin >> n;
    vector<double> a(n);
    int x, y;
    rep(i, 0, n){
        cin >> x >> y;
        a[i] = pow(x * x + y * y, 0.5);
    }
    sort(a.begin(), a.end());
    //cout << a.size();
    //rep(i, 0, n) cout << a[i] << endl;
    int q, s;
    cin >> q;
    rep(i, 0, q){
        cin >> s;
        int m = 0, l = 0, r = n - 1;
        while(l <= r){
            m = (r+l)/2;
            //cout << m << " m" << endl;
            if (a[m] <= s){
                //cout << 'h' << endl;
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        cout << l << endl;
    }
}
//this shit no work