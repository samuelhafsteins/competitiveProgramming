//#pragma GCC optimize("Ofast","unroll-loops")
//#pragma GCC target("avx2,fma")
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

ll modPow (ll b, ll e, ll m){
  if (m == 1)
    return 0;
  
  ll r = 1;

  b %= m;

  while(e){
    if(e%2)
      r = (r*b) % m;

    b = (b*b) % m, e /= 2;
  }
  //cout << r << ' ' << endl;
  return r;
}

ll geoSerMod(ll q, ll exp, ll mod){
  ll factor = 1, sum = 0, temp;

  while(exp > 0 && q != 0){
    if (exp % 2 == 0){
      temp = (factor*modPow(q, exp, mod)) % mod;
      sum = (sum + temp) % mod;
      exp--;
    }
    factor = (((1+q) % mod)*factor) % mod;
    q = (q*q) % mod;
    exp /= 2;
  }

  return (sum + factor) % mod;
}

int main(){
    ll a, b, x, n, m;
    cin >> a >> b >> x >> n >> m;

    ll p1, p2;
    p1 = (modPow(a, n, m) * x) % m;
    p2 = (geoSerMod(a, n-1, m) * b) % m; 

    cout << (p1 + p2) % m;


    return 0;
}