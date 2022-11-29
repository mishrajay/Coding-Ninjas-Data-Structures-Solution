#include <iostream>
#include <vector>
using namespace std;

bool helper(vector<vector<int>> &cake, int n, int ci, int cj, bool **visited, int &count){
	//up
    bool ans=false;
    visited[ci][cj]=true;
    if(ci - 1 >= 0 && cj < n && cake[ci - 1][cj] == 1 && !visited[ci - 1][cj]){
        visited[ci - 1][cj] = true;
        ans=helper(cake, n, ci - 1, cj, visited, ++count);
        if(ans){
            return ans;
        }
    }
    
    //down
    if(ci + 1 < n && cj < n && cake[ci + 1][cj] == 1 && !visited[ci + 1][cj]){
        visited[ci + 1][cj] = true;
        ans= helper(cake, n, ci + 1, cj, visited, ++count);
        if(ans){
            return ans;
        }
    }
    
    //left
    if(ci < n && cj - 1 >= 0 && cake[ci][cj - 1] == 1 && !visited[ci][cj - 1]){
        visited[ci][cj - 1] = true;
        ans= helper(cake, n, ci, cj - 1, visited, ++count);
        if(ans){
            return ans;
        }
    }
    
    //right
    if(ci < n && cj + 1 < n && cake[ci][cj + 1] == 1 && !visited[ci][cj + 1]){
        visited[ci][cj + 1] = true;
        ans= helper(cake, n, ci, cj + 1, visited, ++count);
        if(ans){
            return ans;
        }    
    }
    
    return false;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    bool **visited = new bool*[n];
    for(int i = 0; i < n; i++){
        visited[i] = new bool[n];
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
    
    int count = 1, res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cake[i][j] == 1){
                bool ans = helper(cake, n, i, j, visited, count);
                if(count > res){
                    res = count;
                    count = 1;
                } 
            }
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}