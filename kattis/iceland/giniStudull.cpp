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
    long long n, smList = 0, s = 0;
    cin >> n;
    vi y (n);
    rep(i,0,n){
        cin >> y[i];
        smList += y[i];
    }
    sort(y.begin(), y.end());
    long long sm = y[n - 1] * n;
    for (int i = n - 1; i > -1; --i){
        s += (sm - (smList + y[i] * n - sm));
        sm -= (y[i] - y[i-1 >= 0 ? i-1 : n-1]) * i;
    }
     
    cout << setprecision(20) << s/(2.0*n*smList) << endl;
    return 0;
}