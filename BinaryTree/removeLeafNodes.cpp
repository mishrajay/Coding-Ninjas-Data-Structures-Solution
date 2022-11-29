/*Given a binary tree, remove all leaf nodes from it. Leaf nodes are those nodes, which don't have any children.
Note:
1. Root will also be a leaf node if it doesn't have left and right child. 
2. You don't need to print the tree, just remove all leaf nodes and return the updated root.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output Format:
The updated binary tree, after removing leaf nodes, is printed level wise. Each level is printed in new line.
Constraints
Time Limit: 1 second
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
8
3 10
6 14
*/
#include<iostream>
using namespace std;
#include"binaryTreeNodeUse.cpp"

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    // Write your code here
    if((root == NULL) || (root -> left == NULL && root -> right == NULL)){
        return NULL;
    }
    
    BinaryTreeNode<int>* leftTree = removeLeafNodes(root -> left);
    BinaryTreeNode<int>* rightTree = removeLeafNodes(root -> right);
    root -> left = leftTree;
    root -> right = rightTree;
    
    return root;
}

void printEachLevelInNewLine(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL){
        return;
    }
    
    queue<BinaryTreeNode<int>*> p;
    p.push(root);
    p.push(NULL);
    
    while(!p.empty()){
     
        BinaryTreeNode<int>* front = p.front();
        p.pop();
        
        if(front){
            cout<<front->data<<" ";
        
        	if(front -> left != NULL){
            	p.push(front -> left);
        	}
        
        	if(front -> right != NULL){
            	p.push(front -> right);
        	}
        } 
        
        else {
            if(p.empty()){
                break;
            }          
            else{
                cout<<endl;
                p.push(NULL);
            }   
        }
    	
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    root = removeLeafNodes(root);
    printEachLevelInNewLine(root);
}