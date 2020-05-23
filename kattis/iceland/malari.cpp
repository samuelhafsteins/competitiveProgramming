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

auto FindClosestS(const vector<ll>& v, ll value)
{
    // assert(is_sorted(v.begin(), v.end(), greater<>{}));
    auto it = upper_bound(v.begin(), v.end(), value, less<>{});

    if (it == v.begin()) {
        return it;
    } else if (it == v.end()) {
        return it - 1;
    } else {
        return abs(value - *it) < abs(value - *(it - 1)) ?
               it : it - 1;
    }
}

auto FindClosestL(const vector<ll>& v, ll value)
{
    // assert(is_sorted(v.begin(), v.end(), greater<>{}));
    auto it = lower_bound(v.begin(), v.end(), value, greater<>{});

    if (it == v.begin()) {
        return it;
    } else if (it == v.end()) {
        return it - 1;
    } else {
        return abs(value - *it) < abs(value - *(it - 1)) ?
               it : it - 1;
    }
}

int main(){
    ll n, a, b;
    int m;

    cin >> n >> m;
    vector<ll> f, s;

    cin >> a >> b;

    f.pb(a), s.pb(b);

    rep(i, 0, m - 1){
        cin >> a >> b;

        auto indxL = FindClosestL(f, b);
        auto indxS = FindClosestS(s, a) ;

        cout << *indxL << ' ' << *indxS << endl;

    }

    return 0;
}