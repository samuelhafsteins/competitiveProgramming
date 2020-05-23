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

vvi a(10, vi(2));

int modPow (ll b, ll e, ll m){
  if (m == 1)
    return 0;
  
  int r = 1;

  b %= m;

  while(e){
    if(e%2)
      r = (r*b) % m;

    b = (b*b) % m, e /= 2;
  }
  return r;
}

int geoSerMod(int q, ll exp, int mod){
  int factor = 1, sum = 0, temp;

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
  int a = geoSerMod(10, 42, 1009);
  cout << a << endl;
}

