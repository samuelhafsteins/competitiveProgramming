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

int main() {
    int t, temp = 0;
    string n;
    cin >> t;
    rep(i, 0, t){
        cin >> n;
        vi ans;
        int c = 0;
        int pw = n.size() - 1;
        for (int j = 0; j < n.size(); ++j){
            //cout <<  (int)n[j] - 48 << " int ";
            ans.push_back(((int)n[j] - 48) * pow(10, pw));
            --pw;
        }
        rep(j, 0, ans.size()) if(ans[j] != 0) c++;
        cout << c << endl;
        rep(j, 0, ans.size()) if(ans[j] != 0) cout << ans[j] << ' ';
        cout << endl;
    }
    return 0;
}