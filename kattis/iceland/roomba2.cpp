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
    int H, W, back = 0;
    cin >> H >> W;
    if (H == 1){
        for (int c = 0; c < W; ++c) {
            cout << 0 << " " << c << endl;
        }
        for (int c = W-2; c > -1; --c){
            cout << 0 << " " << c << endl;
        }
    }
    else if (W == 1){
        for (int r = 0; r < H; ++r) {
            cout << r << " " << 0 << endl;
        }
        for (int r = H-2; r > -1; --r){
            cout << r << " " << 0 << endl;
        }
    }
    else if (H % 2 == 0){
        cout << "0 0" << endl;
        for (int r = 0; r < H; ++r){
            for (int c = 1; c < W; ++c){
                cout << r << " " << abs(back - c) << endl;
            }
            back = (back == W ? 0 : W);
        }
        for (int r = H - 1; r >= 0; --r){
            cout << r << ' ' << 0 << endl;
        }
    }
    else if (W % 2 == 0){
        cout << "0 0" << endl;
        for (int c = 0; c < W; ++c){
            for (int r = 1; r < H; ++r){
                cout << abs(back - r) << " " << c << endl;
            }
            back = (back == H ? 0 : H);
        }
        for (int c = W - 1; c >= 0; --c){
            cout << 0 << ' ' << c << endl;
        }
    }
    else {
        cout << "0 0" << endl;
        for (int r = 0; r < H - 2; ++r){
            for (int c = 1; c < W; ++c){
                cout << r << " " << abs(back - c) << endl;
            }
            back = (back == W ? 0 : W);
        }
        back = 1;
        for (int c = W - 1; c > 0; --c){
            if (back) {
                for (int r = H - 2; r < H; ++r){
                    cout << r << ' ' << c << endl;
                }
            }else{
                for (int r = H - 1; r > H-3; --r){
                    cout << r << ' ' << c << endl;
                }
            }
            back = (back == 1 ? 0 : 1);
        }
        cout << H-2 << ' ' << 0 << endl;
        for (int r = H-1; r > -1; --r) {
            cout << r << " " << 0 << endl;
        }

        // for (int r = H - 1; r >= 0; --r){
        //     cout << r << ' ' << 0 << endl;
        // }
    }
    return 0;
}