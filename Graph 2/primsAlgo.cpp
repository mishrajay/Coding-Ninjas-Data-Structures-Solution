#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int findMinWeightVertex(int *weight, int n, bool* visited){
    int minWeightVertex = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minWeightVertex == - 1 || weight[i] < weight[minWeightVertex])){
			minWeightVertex = i;
		}
	}
	return minWeightVertex;
}

void prims(int **edges, int n){
    int *parent = new int[n];
    int *weight = new int[n];
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        weight[i] = INT_MAX;
        visited[i] = false;
    }
    
    parent[0] = -1;
    weight[0] = 0;
    for(int i = 0; i < n - 1; i++){
        int minWeightVertex = findMinWeightVertex(weight, n, visited);
        visited[minWeightVertex] = true;
        for(int j = 0; j < n; j++){
            if(edges[minWeightVertex][j] != 0 && !visited[j]){
                if(edges[minWeightVertex][j] < weight[j]){
                	weight[j] = edges[minWeightVertex][j];
                    parent[j] = minWeightVertex;
                }
            }
        }
    }
    
    cout<<"Minimum Spanning Tree is: "<<endl;
    for(int i = 1; i < n; i++){
        if(i < parent[i]){
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
        else{
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
    }
    
    delete [] visited;
    delete [] weight;
    delete [] parent;
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
        int f, s, weight;
        cin>>f>>s>>weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }
    cout<<endl;
    
    prims(edges, n);
    
    for(int i = 0; i < n; i++){
        delete [] edges[i];
    }
    delete [] edges;
}