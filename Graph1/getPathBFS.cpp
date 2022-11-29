/*
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*/
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int>* getPathBFS(int **edges, int n, int v1, int v2, bool *visited){
    queue<int> q;
    unordered_map<int, int> ourmap;
    q.push(v1);
    visited[v1] = true;
    ourmap[v1] = v1;
    int count = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(i == v1){
                continue;
            }
            
            if(edges[curr][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
                ourmap[i] = curr;
                
                if(i == v2){
                	/*cout<<v2<<" ";
    				int i = v2;
    				while(i != 0){
        				cout<<ourmap[i]<<" ";
        				i = ourmap[i];
    				}
    				cout<<v1<<" ";
                    count = 0;
            		break;
                    */
                    vector<int> * ans = new vector<int>();
                    
                    ans->push_back(v2);
                    int x = v2;
                    while(ourmap[x]!=v1)
                    {
                        ans->push_back(ourmap[x]);
                        x=ourmap[x];
                    }
                    ans->push_back(v1);
                    
                    return ans;
            	}
        	}
    	}
    }
            
    return NULL;     
    
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
    
    vector<int>* ans = getPathBFS(edges, n, v1, v2, visited);
    if(ans){
        //since returned vector was created dynamically, so we've used -> 
        for(int i=0 ;i< ans->size(); i++){
        	cout<< ans->at(i) << " ";
    	}
    }
    
    delete[] visited;
    
    for(int i = 0; i < n; i++){
        delete[] edges[i];
    }
    
    delete[] edges;
}