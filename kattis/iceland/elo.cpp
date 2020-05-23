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

int L[1200], R[1200], A[1200];
int n;
int VIS[6000];
void DFS(int at) {
    if(VIS[at]) return;
    VIS[at] = 1;
    rep(i,0,n) {
        if(L[i] <= at && at <= R[i]) DFS(at + A[i]);
    }
}

int main() {
    int x;
    cin >> n >> x;
    rep(i,0,n) cin >> L[i] >> R[i] >> A[i];
    memset(VIS,0,sizeof(VIS));
    DFS(x);
    int mx = x;
    rep(i,0,6000) if(VIS[i]) mx = i;
    cout << mx << endl;
}
