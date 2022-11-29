/*Given a binary tree with N number of nodes, check if that input tree is BST 
(Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The data of the nodes of the tree is separated by space. If any node does not have 
a left or right child, take -1 in its place. Since -1 is used as an indication whether 
the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
The first and only line of output contains either true or false.
Constraints :
Time Limit: 1 second
Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 1 :
true
Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
Sample Output 2 :
false
*/
#include<iostream>
using namespace std;
#include"BSTheaderFile.cpp"
#include <climits>
bool helper(BinaryTreeNode<int> *root,int mini,int maxi) {
    if(!root) 
        return true;
        
    if(root->data<mini || root->data>maxi) 
        return false;

    return helper(root->left,mini,root->data-1) && helper(root->right,root->data,maxi);
}

bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    return helper(root,INT_MIN,INT_MAX);
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << (isBST(root) ? "true" : "false");
}