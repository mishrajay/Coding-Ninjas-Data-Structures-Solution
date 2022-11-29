#include<iostream>
using namespace std;
#include"binaryTreeNodeUse.cpp"

int height(BinaryTreeNode<int>* root) {
    // Write our code here
    if(root == NULL){
        return 0;
    }
    
    return 1 + max(height(root -> left), height(root -> right));
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << height(root);
}