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

const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

ll N, W;
vii a;
ll memo[1050][1050];
vi ansList;

ll dp(ll at, ll w){
    if (memo[at][w] != -1) return memo[at][w];
    if (at == N) return 0;
    ll mx = dp(at + 1, w);
    if (w + a[at].first <= W) mx = max(mx, dp(at + 1, w + a[at].first) + a[at].second);
    //cout << a[at].first << ' ' << a[at].second << ' ' << mx << endl;
    return memo[at][w] = mx;
}

void bt(ll at, ll weight, ll bst) {
    if(at == N) return;
    if(dp(at+1, weight) == bst) {
        bt(at+1,weight,bst);
    } else {
        ansList.push_back(at);
        bt(at+1, weight + a[at].first, bst - a[at].second);
    }
}

int main(){
    cin >> N >> W;
    a = vii(N);
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < N; i++) {
        cin >> a[i].first >> a[i].second;
    }
    ll ans = dp(0, 0);
    //cout << ans;
    bt(0, 0, ans);
    cout << ansList.size() << ' ' << ans << endl;
    rep(i, 0, ansList.size()){
        cout << ansList[i] << ' ';
    }
    return 0;
}