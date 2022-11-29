/*Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns of the board. 
Each of the following N lines contain M characters. Please note that characters are not space separated. Each character is an uppercase Latin letter.
Output Format :
Print true if there is a cycle in the board, else print false.
Constraints :
2 <= N <= 1000
2 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
3 4
AAAA
ABCA
AAAA
Sample Output 1:
true
*/
#include<bits/stdc++.h>
using namespace std;

bool hasCycleHelper(vector<vector<char>> &board, int n, int m, int ci, int cj, bool **visited, char c, vector<char> v){
    if(v.size() == 4){
        return true;
    }
    
    //up
    if(ci - 1 >= 0 && cj < m && board[ci - 1][cj] == c && !visited[ci - 1][cj]){
        visited[ci - 1][cj] = true;
        v.push_back(c);
        return hasCycleHelper(board, n, m, ci - 1, cj, visited, c, v);
    }
    
    //down
    if(ci + 1 < n && cj < m && board[ci + 1][cj] == c && !visited[ci + 1][cj]){
        visited[ci + 1][cj] = true;
        v.push_back(c);
        return hasCycleHelper(board, n, m, ci + 1, cj, visited, c, v);
    }
    
    //left
    if(ci < n && cj - 1 >= 0 && board[ci][cj - 1] == c && !visited[ci][cj - 1]){
        visited[ci][cj - 1] = true;
        v.push_back(c);
        return hasCycleHelper(board, n, m, ci, cj - 1, visited, c, v);
    }
    
    //right
    if(ci < n && cj + 1 < m && board[ci][cj + 1] == c && !visited[ci][cj + 1]){
        visited[ci][cj + 1] = true;
        v.push_back(c);
        return hasCycleHelper(board, n, m, ci, cj + 1, visited, c, v);
    }
    
    //diagonal left up
    if(ci - 1 >= 0 && cj - 1 >= 0 && board[ci - 1][cj - 1] == c && !visited[ci - 1][cj - 1]){
        visited[ci - 1][cj - 1] = true;
        v.push_back(c);
        return hasCycleHelper(board, n, m, ci - 1, cj - 1, visited, c, v);
    }
    
    //diagonal right up
    if(ci - 1 >= 0 && cj + 1 < m && board[ci - 1][cj + 1] == c && !visited[ci - 1][cj + 1]){
        visited[ci - 1][cj + 1] = true;
        v.push_back(c);
        return hasCycleHelper(board, n, m, ci - 1, cj + 1, visited, c, v);
    }
    
    //diagonal left down
    if(ci + 1 < n && cj - 1 >= 0 && board[ci + 1][cj - 1] == c && !visited[ci + 1][cj - 1]){
        visited[ci + 1][cj - 1] = true;
        v.push_back(c);
        return hasCycleHelper(board, n, m, ci + 1, cj - 1, visited, c, v);
    }
    
    //diagonal right down
    if(ci + 1 < n && cj + 1 < m && board[ci + 1][cj + 1] == c && !visited[ci + 1][cj]){
        v.push_back(c);
        visited[ci + 1][cj + 1] = true;
        return hasCycleHelper(board, n, m, ci + 1, cj + 1, visited, c, v);
    }
    
    return false;
}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    bool **visited = new bool*[n];
    for(int i = 0; i < n; i++){
        visited[i] = new bool[n];
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
    
    for(int i = 0; i < 26; i++){
        char c = 65 + i;
        vector<char> v;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'c'){
                    if(hasCycleHelper(board, n, m, i, j, visited, c, v)){
            			return true;
        			}
                    while(!v.empty()){
                        v.pop_back();
                    }
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

    cout << (hasCycle(board, n, m) ? "true" : "false");
}