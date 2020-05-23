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
    int n, m, ans = 0;
    cin >> n;
    vvi s(n, vi(5));
    rep(i, 0, n){
        rep(j, 0, 4){
            cin >> s[i][j];
        }
    }
    cin >> m;
    vvi mines(m, vi(4));
    rep(i, 0, m){
      rep(j, 0, 4){
            cin >> mines[i][j];
        }
    }
    vi mine;
    double l;
    //cout << mines.size() << endl;
    //O(N(N+M))
    while (int t = mines.size()){ //O(N+M)
      mine = mines[t-1];
      mines.pop_back();
      //cout << mines.size() << endl;
      rep(i, 0, n){ //O(N)
        l = pow((s[i][0] - mine[0]) * (s[i][0] - mine[0]) + (s[i][1] - mine[1]) * (s[i][1] - mine[1]) + (s[i][2] - mine[2]) * (s[i][2] - mine[2]), 0.5);
        //cout << l << " l" << endl;
        if (s[i][3] + mine[3] >= l && !s[i][4]){
          s[i][4] = 1;
          s[i][3] *= 2;
          mines.push_back(s[i]);
        }
      }
    }
    rep (i, 0, n){
      //cout << s[i][4];
      if (!s[i][4]) ++ans;
    }
    cout << ans << endl;
}

//d = ((x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2)^1/2