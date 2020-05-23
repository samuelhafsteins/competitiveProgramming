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

string S, T, A = "";
int memo[3050][3050];

int dp(int s, int t){ 
    if (s == -1 || t == -1) return 0;
    if (memo[s][t] != -1) return memo[s][t];
    if (S[s] == T[t]) return memo[s][t] = 1 + dp(s-1, t-1);
    else return memo[s][t] = max(dp(s - 1, t), dp(s, t - 1));
}

void bt(int s, int t, int ans){
    if (ans == 0) return;
    if (s == -1 || t == -1) return;
    if (S[s] == T[t]){
        bt(s - 1, t - 1, ans - 1);
        A += S[s];
        return;
    }
    if (dp(s-1, t) == ans){
        bt(s-1, t, ans);
        return;
    }
    else {
        bt(s, t-1, ans);
        return;
    }
}

int main(){
    cin >> S >> T;
    memset(memo, -1, sizeof(memo));
    cout << dp(S.size() - 1, T.size() - 1);
    bt(S.size() - 1, T.size() - 1, dp(S.size() - 1, T.size() - 1));
    cout << A;
    return 0;
}