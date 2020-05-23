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
    int n, k, c = 0;
    cin >> n >> k;
    vector<vector<char>> g(2, vector<char>(n));
    rep(i, 0, 2){
        rep(j, 0, n) cin >> g[i][j];
    }
    rep(i, 0, n){
        if (g[0][i] == 'o'){
            if (g[1][i-1] == 'o' && i > 0) c += 1;
            if (g[1][i] == 'o') c += 1;
            if (g[1][i+1] == 'o' && i < n - 1) c += 1;
        }
    }
    char q;
    int x, y;
    rep(i, 0, k){
        cin >> q;
        //cout << q;
        if (q == 'U'){
            cin >> x >> y;
            x -= 1;
            y -= 1;
            if (g[x][y] == 'o') {
                if (g[x == 1 ? 0 : 1][y-1] == 'o') c -= 1;
                if (g[x == 1 ? 0 : 1][y] == 'o') c -= 1;
                if (g[x == 1 ? 0 : 1][y+1] == 'o') c -= 1;
                g[x][y] = '.';
            }
            else {
                if (g[x == 1 ? 0 : 1][y-1] == 'o') c += 1;
                if (g[x == 1 ? 0 : 1][y] == 'o') c += 1;
                if (g[x == 1 ? 0 : 1][y+1] == 'o') c += 1;
                //cout << c << endl;
                g[x][y] = 'o';
            }
        }
        else {
            if (c) cout << "Neibb" << endl;
            else cout << "Jebb" << endl;
        }
    }
    return 0;
}