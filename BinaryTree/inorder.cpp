#include<iostream>
using namespace std;
#include"binaryTreeNodeUse.cpp"

void inOrder(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root != NULL){
        inOrder(root -> left);
        cout<<root -> data<<" ";
        inOrder(root -> right);
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    inOrder(root);
}