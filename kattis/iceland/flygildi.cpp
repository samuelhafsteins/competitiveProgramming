#pragma GCC optimize("Ofast","unroll-loops")
#pragma GCC target("avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<double> vd;
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

int n;
double m[10][10];

double travllingSalesmanProblem(int s)  { 
    // store all vertex apart from source vertex 
    vector<int> vertex; 
    for (int i = 0; i < n + 1; i++) 
        if (i != s) 
            vertex.push_back(i); 
  
    // store minimum weight Hamiltonian Cycle. 
    double min_path = INT_MAX; 
    do { 
  
        // store current Path weight(cost) 
        double current_pathweight = 0; 
          
        // compute current path weight 
        int k = s; 
        for (int i = 0; i < vertex.size(); i++) { 
            current_pathweight += m[k][vertex[i]]; 
            k = vertex[i]; 
        } 
        current_pathweight += m[k][s]; 
  
        // update minimum 
        min_path = min(min_path, current_pathweight); 
         
    } while (next_permutation(vertex.begin(), vertex.end())); 
  
    return min_path; 
} 

int main(){
    int miny = 0, maxy = 0;
    int x, y;
    cin >> n;
    vii g(n + 1);
    rep(i, 1, n + 1){
        cin >> g[i].fs >> g[i].sc;
        miny = min(miny, g[i].sc);
        maxy = max(maxy, g[i].sc);
    }
    if (n > 8){
        cout << (abs(miny) + maxy) * 2 << endl;
    }
    else {
        rep(i, 0, n + 1){
            rep(j, 0, n + 1){
                m[i][j] = pow((g[i].fs - g[j].fs) * (g[i].fs - g[j].fs) + (g[i].sc - g[j].sc) * (g[i].sc - g[j].sc), 0.5);
                //cout << m[i][j] << endl;
            }
        }
        cout << setprecision(10) << travllingSalesmanProblem(0) << endl;
    }
    
    //rep(i, 0, n) cout << setprecision(6) << m[i][1] << endl;
    return 0;
}