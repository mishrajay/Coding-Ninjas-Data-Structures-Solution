#include<iostream>
using namespace std;
#include"binaryTreeNodeUse.cpp"
int getSum(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return 0;
    }
    
    int sum = root -> data;
    sum += getSum(root -> left);
    sum += getSum(root -> right);
    
    return sum;
}
int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << getSum(root);
}