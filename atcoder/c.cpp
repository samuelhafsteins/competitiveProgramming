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

vi T[3];
int N;
int memo[4][100050];


int dp(int at, int last){
    int mx = 0;
    if (at > N - 1) return 0;
    if (memo[last][at] != -1) return memo[last][at];
    for (int i = 0; i < 3; ++i) if (last != i) mx = max(mx, dp(at + 1, i) + T[i][at]);
    //cout << at << " " << last << endl;
    return memo[last][at] = mx;
}

int main(){
    cin >> N;
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < 3; ++i){
        T[i] = vi(N);
    }
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < 3; ++j){
            cin >> T[j][i];
        }
    }
    cout << dp(0, 3) << endl;
    return 0;
}