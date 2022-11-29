#include<iostream>
using namespace std;
#include"binaryTreeNodeUse.cpp"

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    if(root == NULL){
        return false;
    }
    
    if(root -> data == x){
        return true;
    }
    
    return isNodePresent(root -> left, x) || isNodePresent(root -> right, x);
}

int main() {
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int x;
    cin >> x;
    cout << ((isNodePresent(root, x)) ? "true" : "false");
}