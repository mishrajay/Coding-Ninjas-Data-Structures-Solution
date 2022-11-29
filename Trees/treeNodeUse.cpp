#include<iostream>
#include<queue>
using namespace std;
#include "treeNode.h"

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"enter data of root"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter the num of children of "<<front -> data<<endl;
        int numChild;
        cin>>numChild;
        for(int i = 1; i <= numChild; i++){
            cout<<"enter the "<<i<<"th child of "<<front -> data<<endl;
            int childData;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front -> children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

TreeNode<int>* takeInput(){
    int rootData;
    cout<<"enter data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cout<<"enter num of children of "<<rootData<<endl;
    cin>>n;
    for(int i = 0; i < n; i++){
        TreeNode<int>* child = takeInput();
        root -> children.push_back(child);
    }

    return root;
}

void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int>*> p;
    p.push(root);
    while(!p.empty()){
        root = p.front();
        p.pop();
        cout<<root -> data<<":";
        for(int i = 0; i < root -> children.size(); i++){
            p.push(root -> children[i]);
        	cout<<root -> children[i] -> data;
            if(root -> children.size() - i != 1){
                cout<<",";
            }
    	}
        cout<<endl;
    }
}

void printTree(TreeNode<int>* root){
    //edge case
    if(root == NULL){
        return;
    }

    cout<<root -> data<<": ";
    for(int i = 0; i < root -> children.size(); i++){
        cout<<root -> children[i] -> data<<",";
    }
    cout<<endl;
    for(int i = 0; i < root -> children.size(); i++){
        printTree(root -> children[i]);
    }
}

//depth of tree
void printAtLevelK(TreeNode<int>* root, int k){
    if(root == NULL){
        return;
    }

    if(k == 0){
        cout<<root -> data<<" ";
        return;
    }

    for(int i = 0; i < root -> children.size(); i++){
        printAtLevelK(root -> children[i], k - 1);
    }    
}

// **************TIME AND SPACE COMPLEXITY**************
// TIME COMPLEXITY - O(N)
// SPACE COMPLEXITY - O(H)
// where N and H are number of nodes and height/depth respectively

int countNodes(TreeNode<int>* root){
    int ans = 1;
    for(int i = 0; i < root -> children.size(); i++){
        ans += countNodes(root -> children[i]);
    }
    return ans;
}
/*
int main(){
    /*treeNode<int> *root = new treeNode<int>(10);
    treeNode<int> *node1 = new treeNode<int>(20);
    treeNode<int> *node2 = new treeNode<int>(30);
    
    root -> children.push_back(node1);
    root -> children.push_back(node2);
    

    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    printAtLevelK(root, 3);
    int nodes = countNodes(root);
    cout<<endl<<nodes<<endl;
}*/