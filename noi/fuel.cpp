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

int N, D;
int X, A, B;
vvi G;
int memo[300050];

int dp(int at, ll f){
  if (at == N) return 0;
  if (memo[at] != -1) return memo[at];
  X = G[at][0], A = G[at][1], B G[at][2]
  dp (at + 1, A + B)
  if (f - X >= 0) dp (at + 1,f - X + A)
}


int main(){
  cin >> N >> D;
  G = vvi(N);
  memset(memo, -1, sizeof(memo));
  rep(i, 0, N){
    rep(j, 0, 3){
      int t;
      cin >> t;
      G[i].pb(t);
    }
  }
  sort(G.begin(), G.end());
  rep(i, 0, N){
    rep(j, 0, 3){
      cout << G[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}