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

int n, m;
vvii mp(501, vii(501));
int ans[501][501][32];

// void proc(){
//     rep(x, 0, n){
//         rep(y, 0, m){
            
//         }
//     }
// }

int main(){
    char temp;
    cin >> n >> m;
    rep(i, 0 ,n){
        rep(j, 0, m){
            cin >> temp;
            if (temp == '>') mp[i][j] = {1, 0};
            else if (temp == '<') mp[i][j] = {-1, 0};
            else if (temp == 'v') mp[i][j] = {0, 1};
            else if (temp == '^') mp[i][j] = {0, -1};
        }
    }
    int q, x, y, k;
    cin >> q;
    rep(i, 0, q){
        cin >> x >> y >> k;
    }
    //cout << mp[0][0].sc << endl;
    return 0;
}