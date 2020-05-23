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

int H, W;

int main(){
    cin >> H >> W;
    vector<vi> grid(H, vi(W));
    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i < H -1; ++i){
        for (int j = 1; j < W - 1; ++j){
            int nm = grid[i][j];
            if (nm < grid[i-1][j] && nm < grid[i][j-1] && nm < grid[i+1][j] && nm < grid[i][j+1]){
                cout << "Jebb";
                return 0;
            }
        }
    }
    cout << "Neibb";
    return 0;
}