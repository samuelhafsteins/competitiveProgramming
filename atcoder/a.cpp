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
const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

int n;
vi h;
int memo[100050];

int dp(int at){
    if(memo[at] != -1) return memo[at];
    if(at == n-1) return 0;
    int ans = dp(at + 1) + abs(h[at] - h[at + 1]);
    if (n - at - 1 > 1) ans = min(ans, dp(at + 2) + abs(h[at] - h[at + 2]));
    return memo[at] = ans;
}

int main(){
    cin >> n;
    h = vi(n);
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < n; ++i){
        cin >> h[i];
    }
    cout << dp(0) << endl;
    return 0;
}