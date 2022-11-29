/*
Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.
Input Format:
There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.
Output Format:
The first and only line of output contains boolean value, either true or false, as described in problem statement.
Constraints:
The cell values lie in the range: [0, 9]
Time Limit: 1 second 
Note:
Input are given in a way that backtracking solution will work in the provided time limit.
Sample Input 1:
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output 1:
true
*/

#include<bits/stdc++.h>
using namespace std;

bool isSafeIn3by3Grid(int grid[9][9], int row, int col, int val){
    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);
    for(int i = rowFactor; i < rowFactor + 3; i++){
        for(int j = colFactor; j < colFactor + 3; j++){
            if(grid[i][j] == val){
                return false;
            }
        }
    }
    return true;
}

bool isSafeInColumn(int grid[9][9], int col, int val){
    for(int i = 0; i < 9; i++){
        if(grid[i][col] == val){
            return false;
        }
    }
    return true;
}

bool isSafeInRow(int grid[9][9], int row, int val){
    for(int i = 0; i < 9; i++){
        if(grid[row][i] == val){
            return false;
        }
    }
    return true;
}

bool findEmptyPos(int grid[9][9], int &row, int &col){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(grid[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[9][9], int row, int col, int val){
    return isSafeInRow(grid, row, val) && isSafeInColumn(grid, col, val) && isSafeIn3by3Grid(grid, row, col, val);
}

bool sudokuSolver(int grid[9][9]){
    int row, col;
    if(!findEmptyPos(grid, row, col)){
        return true;
    }

    for(int i = 1; i <= 9; i++){
        if(isSafe(grid, row, col, i)){
            grid[row][col] = i;
            if(sudokuSolver(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int grid[9][9];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin>>grid[i][j];
        }
    }

    if(sudokuSolver(grid)){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"not able to solve the given sudoku"<<endl;
    }
}