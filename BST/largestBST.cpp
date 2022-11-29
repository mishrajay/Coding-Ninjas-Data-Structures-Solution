/*Given a Binary tree, find the largest BST subtree. That is, you need to find the 
BST with maximum height in the given binary tree. You have to return the height of 
largest BST.
Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The data of the nodes of the tree is separated by space. If any node does not have 
left or right child, take -1 in its place. Since -1 is used as an indication whether 
the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format:
The first and only line of output contains the height of the largest BST.
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2
*/
#include<iostream>
using namespace std;
#include"BSTheaderFile.cpp"
#include<climits>
// #include<climits>
// #include<cmath>

// class isBstReturn{
//   public :
//     int minimum;
//     int maximum;
//     int height;
//     bool isBst;
// };

// isBstReturn helper(BinaryTreeNode<int>* root){
//     if(root == NULL){
//         isBstReturn output;
//         output.minimum = INT_MAX;
//         output.maximum = INT_MIN;
//         output.height = 0;
//         bool isBst = true;
//         return output;
//     }
    
//     isBstReturn leftTree = helper(root -> left);
//     isBstReturn rightTree = helper(root -> right);
    
//     if(!(leftTree.isBst && root -> data > leftTree.maximum)){
//         leftTree.isBst = false;
//     }
//     if(!(rightTree.isBst && root -> data < rightTree.minimum)){
//         rightTree.isBst = false;
//     }
    
//     int minimum = min(root -> data, min(leftTree.minimum, rightTree.minimum));
//     int maximum = max(root -> data, max(leftTree.maximum, rightTree.maximum));
    
//     bool finalisBst = (leftTree.maximum < root -> data) && (rightTree.minimum > root -> data) 
//         && leftTree.isBst && rightTree.isBst;    
    
//     isBstReturn output;
//     output.minimum = minimum;
//     output.maximum = maximum;
//     output.isBst = finalisBst;
//     output.height = 1 + max(leftTree.height, rightTree.height);
    
//     return output;
    
// }

// int largestBSTSubtree(BinaryTreeNode<int> *root) {
//     // Write your code here
//     return helper(root).height;
    
// }

#include<climits>
int height(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    
    return 1 + max(height(root -> left), height(root -> right));
}

bool isBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root -> data < min || root -> data > max){
        return false;
    }
    
    bool isLeftOK = isBST(root -> left, min, root -> data -1);
    bool isRightOK = isBST(root -> right, root -> data + 1, max);
    
    return isLeftOK && isRightOK;
}

int largestBSTSubtree(BinaryTreeNode<int> *root)
{	
    if(isBST(root))
    {
        return height(root);
    }
    else
    {
        int ans1 = largestBSTSubtree(root -> left);
        int ans2 = largestBSTSubtree(root -> right);
        
        return max(ans1, ans2);
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << largestBSTSubtree(root);
    delete root;
}