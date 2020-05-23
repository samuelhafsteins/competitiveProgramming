// #pragma GCC optimize("Ofast","unroll-loops")
// #pragma GCC target("avx2,fma")
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

class object
{
    public:
        int x, y, z, r;
        bool exploded{false};
    
    friend istream& operator>> (istream& in, object& obj)
    {
        in >> obj.x >> obj.y >> obj.z >> obj.r;
        return in;
    }
    friend ostream& operator<< (ostream& out, const object& obj)
    {
        out << obj.x << ' ' << obj.y << ' ' << obj.z << ' ' << obj.r;
        return out;
    }

    void explode(vector<object>& ships, vector<object>& mines)
    {
        for (object& ship : ships)
        {
            double l{pow(pow(ship.x - this->x, 2) + pow(ship.y - this->y, 2) + pow(ship.z - this->z, 2), 0.5)};
            if (ship.r + this->r >= l && !ship.exploded)
            {
                ship.r *= 2;
                mines.push_back(ship);
                ship.exploded = true; 
            }
        }
    }
};

int main(void)
{
    int n, m, ans = 0;
    cin >> n;
    vector<object> ships(n);
    for (int i{0}; i < n; ++i)
    {
        cin >> ships[i];
    }
    cin >> m;
    vector<object> mines(m);
    for (int i{0}; i < m; ++i)
    {
        cin >> mines[i];
    }
    object mine;
    while (int t = mines.size()){
        mine = mines[t-1];
        mines.pop_back();
        mine.explode(ships, mines);
    }
    rep(i, 0, n){
        if (!ships[i].exploded) ++ans;
    }
    cout << ans;
    return 0;//
}
//d = ((x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2)^1/2