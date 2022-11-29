/*Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1
*/
#include <bits/stdc++.h>
using namespace std;
bool hasPathHelper(vector<vector<char>> &board, int n, int m, int ci, int cj, vector<vector<bool>> &visited, string s){       
    if(s.size() == 0){
        return true;
    }
    
    //up
    bool ans=false;
    visited[ci][cj]=true;
    if(ci - 1 >= 0 && cj < m && board[ci - 1][cj] == s[0] && !visited[ci - 1][cj]){
        visited[ci - 1][cj] = true;
        ans=hasPathHelper(board, n, m, ci - 1, cj, visited, s.substr(1));
        if(ans){
            return ans;
        }
        visited[ci - 1][cj] =false;
    }
    
    //down
    if(ci + 1 < n && cj < m && board[ci + 1][cj] == s[0] && !visited[ci + 1][cj]){
        visited[ci + 1][cj] = true;
        ans= hasPathHelper(board, n, m, ci + 1, cj, visited, s.substr(1));
        if(ans){
            return ans;
        }
        visited[ci + 1][cj] = false;
    }
    
    //left
    if(ci < n && cj - 1 >= 0 && board[ci][cj - 1] == s[0] && !visited[ci][cj - 1]){
        visited[ci][cj - 1] = true;
        ans= hasPathHelper(board, n, m, ci, cj - 1, visited, s.substr(1));
        if(ans){
            return ans;
        }
        visited[ci][cj-1] = false;
    }
    
    //right
    if(ci < n && cj + 1 < m && board[ci][cj + 1] == s[0] && !visited[ci][cj + 1]){
        visited[ci][cj + 1] = true;
        ans= hasPathHelper(board, n, m, ci, cj + 1, visited, s.substr(1));
        if(ans){
            return ans;
        }
        visited[ci][cj+1] = false;
        
    }
    
    //diagonal left up
    if(ci - 1 >= 0 && cj - 1 >= 0 && board[ci - 1][cj - 1] == s[0] && !visited[ci - 1][cj - 1]){
        visited[ci - 1][cj - 1] = true;
        ans= hasPathHelper(board, n, m, ci - 1, cj - 1, visited, s.substr(1));
        if(ans){
            return ans;
        }
        visited[ci - 1][cj-1] = false;
    }
    
    //diagonal right up
    if(ci - 1 >= 0 && cj + 1 < m && board[ci - 1][cj + 1] == s[0] && !visited[ci - 1][cj + 1]){
        visited[ci - 1][cj + 1] = true;
        ans= hasPathHelper(board, n, m, ci - 1, cj + 1, visited, s.substr(1));
        if(ans){
            return ans;
        }
        visited[ci - 1][cj+1] = false;
    }
    
    //diagonal left down
    if(ci + 1 < n && cj - 1 >= 0 && board[ci + 1][cj - 1] == s[0] && !visited[ci + 1][cj - 1]){
        visited[ci + 1][cj - 1] = true;
        ans= hasPathHelper(board, n, m, ci + 1, cj - 1, visited, s.substr(1));
        if(ans){
            return ans;
        }
        visited[ci + 1][cj-1] = false;
    }
    
    //diagonal right down
    if(ci + 1 < n && cj + 1 < m && board[ci + 1][cj + 1] == s[0] && !visited[ci + 1][cj + 1]){
        visited[ci + 1][cj + 1] = true;
        ans= hasPathHelper(board, n, m, ci + 1, cj + 1, visited, s.substr(1));
        if(ans){
            return ans;
        }
        visited[ci + 1][cj+1] = false;
    }
    visited[ci][cj]=false;
    return ans;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
	for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
        	if(board[i][j] == 'C' && !visited[i][j]){
                string s = "ODINGNINJA";
                bool res = hasPathHelper(board, n, m, i, j, visited, s);
                if(res){
                    return true;
                }
            }    
        }   
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}