#include<iostream>
#include<queue>
using namespace std;
#include"binaryTreeNode.h"

BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}

/*
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
 Sample Output 1:
8:L:3,R:10
3:L:1,R:6
10:L:-1,R:14
1:L:-1,R:-1
6:L:4,R:7
14:L:13,R:-1
4:L:-1,R:-1
7:L:-1,R:-1
13:L:-1,R:-1
*/
void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front -> data<<":";
       
		if(front -> left == NULL){
            cout<<"L:-1,";
        }
        else{
            pendingNodes.push(front -> left);
            cout<<"L:"<<front -> left -> data<<",";
        }
           
        if(front -> right == NULL){
            cout<<"R:-1"<<endl;
        }
        else{
            pendingNodes.push(front -> right);
            cout<<"R:"<<front -> right -> data<<endl;
        }
    }
}

int countNodes(BinaryTreeNode<int>* root){
    //base case
    if(root == NULL){
        return 0;
    }

    return 1 + countNodes(root -> left) + countNodes(root -> right);
}

//inorder printing means to first print the left then the root and then the right
//inorder printing is only applicable in binary trees
void inorder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout<<root -> data<<" ";
    inorder(root -> right);
}

//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
/*
int main(){

    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout<<"num of nodes: "<<countNodes(root)<<endl;
    inorder(root);
    delete root;
    /*BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(20);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(30);
    root -> left = node1;
    root -> right = node2;
}*/