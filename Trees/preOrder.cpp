#include<bits/stdc++.h>
#include"./Trees/treeNodeUse.cpp"
using namespace std;

void preOrder(TreeNode<int>* root){
    if(root == NULL){
        return;
    }

    if(!root -> children.size()){
        cout<<root -> data<<" ";
        return;
    }
    cout<<root -> data<<" ";

    for(int i = 0; i < root -> children.size(); i++){
        preOrder(root -> children[i]);  
    }
    
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    preOrder(root);
}