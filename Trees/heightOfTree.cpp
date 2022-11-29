#include<iostream>
using namespace std;
#include"treeNodeUse.cpp"

int getHeight(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return 0;
    }
    /*
    int height = 0;
    for(int i = 0; i < root -> children.size(); i++){
        height = max(height,getHeight(root -> children[i]));
    }
    return 1 + height;   
    */
    int height = 0;
    for(int i = 0; i < root -> children.size(); i++){
        int smallHeight = getHeight(root -> children[i]);
        if(smallHeight > height){
            height = smallHeight;
        }
    }
    
    return height + 1;
}
//10 3 20 30 40 2 50 60 2 70 80 0 0 0 0 3 90 100 110 0 0 0
int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout << getHeight(root);
}