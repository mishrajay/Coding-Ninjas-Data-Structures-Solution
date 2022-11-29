/*Given a sorted integer array A of size n, which contains all unique elements. 
You need to construct a balanced BST from this input array. Return the root of 
constructed BST.
Note: If array size is even, take first mid as root.
Input format:
The first line of input contains an integer, which denotes the value of n. 
The following line contains n space separated integers, that denote the values of array.
Output Format:
The first and only line of output contains values of BST nodes, printed in pre order 
traversal.
Constraints:
Time Limit: 1 second
Sample Input 1:
7
1 2 3 4 5 6 7
Sample Output 1:
4:L:2,R:6
2:L:1,R:3
6:L:5,R:7
1:L:-1,R:-1
3:L:-1,R:-1
5:L:-1,R:-1
7:L:-1,R:-1
*/
#include<iostream>
using namespace std;
#include"BSTheaderFile.cpp"
BinaryTreeNode<int>* helper(int *input, int si, int ei){
    if(si > ei){
        return NULL;
    }
    int mid = (si + ei) / 2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    
    root -> left = helper(input, si, mid - 1);
    root -> right = helper(input, mid + 1, ei);
    
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    BinaryTreeNode<int>* root = helper(input, 0, n - 1);
    return root;
}

int main() {
    int size;
    cin >> size;
    int* input = new int[size];

    for (int i = 0; i < size; i++) cin >> input[i];

    BinaryTreeNode<int>* root = constructTree(input, size);
    printLevelWise(root);
    delete[] input;
}