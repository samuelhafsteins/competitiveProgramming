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

int N, W;
vii a;
ll memo[105][100050];


ll dp(int at, int w){
    if (memo[at][w] != -1) return memo[at][w];
    if (at > N - 1) return 0;
    ll mx = dp(at + 1, w);
    if (w + a[at].first <= W) mx = max(mx, dp(at + 1, w + a[at].first) + a[at].second);
    //cout << a[at].first << ' ' << a[at].second << ' ' << mx << endl;
    return memo[at][w] = mx;
}

void bt(){
    
    return;
}

int main(){
    cin >> N >> W;
    a = vii(N);
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < N; i++) {
        cin >> a[i].first >> a[i].second;
    }
    cout << dp(0, 0);
    return 0;
}