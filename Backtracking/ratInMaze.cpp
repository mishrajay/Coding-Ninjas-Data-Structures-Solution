/*
You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.
Input Format
The first line of input contains an integer, that denotes the value of N.
Each of the following N lines denote rows of the binary matrix and contains either 0 or 1. Each row of the binary matrix contains N elements. 
Output Format :
Every possible solution has to be printed on a separate line. Each of the possible solution will have N*N elements, printed row wise and separated by space. The cells that are part of the path should be 1 and remaining all cells should be 0. Please refer to sample test cases for more clarity.   
Constraints
1 <= N <= 18
0 <= Number of cells with value 1 <= 15
Time Limit: 1 second
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Explanation :
Only 1 path is possible.

Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 
Explanation:
As described in the Sample Output 2, four paths are possible.
*/

#include<bits/stdc++.h>
using namespace std;
int maze[11][11];
int path[11][11];

void print(int n, int row, int col){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<path[i][j]<<" ";
        }
    }
    cout<<endl;
}

void ratInMazeHelper(int n, int row, int col){
    //base case
    if(row == n - 1 && col == n - 1){
        path[row][col] = 1;
        print(n, row, col);
        return;
    }

    if(row > n-1 || row < 0 || col > n-1 || col < 0 || maze[row][col] == 0 || path[row][col] == 1){
        return;
    }

    path[row][col] = 1;

    //up
    ratInMazeHelper(n, row - 1, col);
    
    //down
    ratInMazeHelper(n, row + 1, col);

    //left
    ratInMazeHelper(n, row, col - 1);

    //up
    ratInMazeHelper(n, row, col + 1);

    path[row][col] = 0;
}

void ratInMaze(int n){
    memset(path, 0, 11*11*sizeof(int));
    ratInMazeHelper(n, 0, 0);
}

int main(){
    int n;
    cin>>n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>maze[i][j];
        }
    }
    ratInMaze(n);
}