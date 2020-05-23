#pragma GCC optimize("Ofast","unroll-loops")
#pragma GCC target("avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
const ll INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

ll N;
ll W;
vii a;
ll memo[105][100050];


ll dp(ll at, ll v){
    if (memo[at][v] != -1) return memo[at][v];
    if (v == 0) return 0;
    if (at > N - 1) return W + 1;
    ll mn = dp(at + 1, v);
    if (v >= a[at].second) mn = min(mn, dp(at + 1, v - a[at].second) + a[at].first);
    
    //cout << a[at].first << ' ' << a[at].second << ' ' << mx << endl;
    return memo[at][v] = mn;
}

int main(){
    cin >> N >> W;
    a = vii(N);
    memset(memo, -1, sizeof(memo));
    for (ll i = 0; i < N; i++) {
        cin >> a[i].first >> a[i].second;
    }
    ll best = 0;
    rep(i, 0, 100001){
        ll w = dp(0, i);
        if (w <= W) best = i;
    }
    cout << best;
    return 0;
}
