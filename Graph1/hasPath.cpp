/*
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.
Constraints :
0 <= V <= 1000
0 <= E <= 1000
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= V - 1
0 <= v2 <= V - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
*/

#include <iostream>
using namespace std;

bool hasPath(int **edges, int n, bool* visited, int v1, int v2){
    if(v1 == v2){
        return true;
    }
   
    visited[v1] = true;
    bool res = false;
    for(int i = 0; i < n; i++){
        if(edges[v1][i] == 1 && !visited[i]){
        	res = hasPath(edges, n, visited, i, v2);    
            if(res == true){
                return true;
            }
        }  
    }
    
    return res;
}

int main() {
    int n, e;
    cin>>n>>e;
    int **edges = new int*[n];
    for(int i = 0; i < n; i++){
        edges[i] = new int[n];
        for(int j = 0; j < n; j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i = 0; i < e; i++){
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    int v1, v2;
    cin>>v1>>v2;
    
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    
    bool res = hasPath(edges, n, visited, v1, v2);
    if(res == true){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}