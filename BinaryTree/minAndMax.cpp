/*For a given Binary Tree of type integer, find and return the minimum and the 
maximum data values.
Return the output as an object of Pair class, which is already created.
Note:
All the node data will be unique and hence there will always exist a minimum and 
maximum node data.
Input Format:
The first and the only line of input will contain the node data, all separated by a 
single space. Since -1 is used as an indication whether the left or right node data 
exist for root, it will not be a part of the node data.
Output Format:
The only line of output prints two integers denoting the minimum and the maximum data 
values respectively. A single line will separate them both.
Constraints:
2 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
1 14
Sample Input 2:
10 20 60 -1 -1 3 50 -1 -1 -1 -1 
Sample Output 2:
3 60
*/
#include<iostream>
using namespace std;
#include"binaryTreeNodeUse.cpp"
/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/
#include<climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
        pair<int, int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }
    
    pair<int, int> leftTree = getMinAndMax(root -> left);
    pair<int, int> rightTree = getMinAndMax(root -> right);
    
    int minimun = min(root -> data, min(leftTree.first, rightTree.first));
    int maximum = max(root -> data, max(leftTree.second, rightTree.second));
    
    pair<int, int> p;
    p.first = minimun;
    p.second = maximum;
    return p;
    
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise ();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}