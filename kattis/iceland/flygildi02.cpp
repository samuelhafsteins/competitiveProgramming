
// CPP program to implement traveling salesman 
// problem using naive approach. 
#include <bits/stdc++.h> 
using namespace std; 

int n;
  
// implementation of traveling Salesman Problem 
int travllingSalesmanProblem(int graph[][n], int s) 
{ 
    // store all vertex apart from source vertex 
    vector<int> vertex; 
    for (int i = 0; i < n; i++) 
        if (i != s) 
            vertex.push_back(i); 
  
    // store minimum weight Hamiltonian Cycle. 
    int min_path = INT_MAX; 
    do { 
  
        // store current Path weight(cost) 
        int current_pathweight = 0; 
          
        // compute current path weight 
        int k = s; 
        for (int i = 0; i < vertex.size(); i++) { 
            current_pathweight += graph[k][vertex[i]]; 
            k = vertex[i]; 
        } 
        current_pathweight += graph[k][s]; 
  
        // update minimum 
        min_path = min(min_path, current_pathweight); 
         
    } while (next_permutation(vertex.begin(), vertex.end())); 
  
    return min_path; 
} 
  
// driver program to test above function 
int main() 
{
    cin >> n;
    // matrix representation of graph 
    int graph[n][n];

    int s = 0; 
    cout << travllingSalesmanProblem(graph, s) << endl; 
    return 0; 
} 
