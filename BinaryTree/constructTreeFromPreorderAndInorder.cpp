/*For a given preorder and inorder traversal of a Binary Tree of type integer stored 
in an array/list, create the binary tree using the given two arrays/lists. You just 
need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 
Input Format:
The first line of input contains an integer N denoting the size of the list/array. 
It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. 
It represents the preorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. 
It represents the inorder-traversal of the binary tree.
Output Format:
The given input tree will be printed in a level order fashion where each level will 
be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will 
separate them.
Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
5 6 2 3 9 10 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
9 
*/
#include<iostream>
using namespace std;
#include"binaryTreeNodeUse.cpp"

BinaryTreeNode<int>* helper(int *preorder, int *inorder, int inS, int inE, int preS, int preE){
	if(inS > inE){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[preS]);
    
    int count = -1;
    for(int i = inS; i <= inE; i++){
        if(inorder[i] == root -> data){
            count = i;
            break;
        }
    }
    
    int leftInS = inS;
    int leftInE = count - 1;
    int leftPreS = preS + 1;
    int leftPreE = leftPreS + leftInE - leftInS;
    int rightInS = count + 1;
    int rightInE = inE;
    int rightPreS = leftPreE + 1;
    int rightPreE = preE;
    
    BinaryTreeNode<int>* leftNode = helper(preorder, inorder, leftInS, leftInE, leftPreS, leftInE);
    BinaryTreeNode<int>* rightNode = helper(preorder, inorder, rightInS, rightInE, rightPreS, rightPreE);
    root -> left = leftNode;
    root -> right = rightNode;
    
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    BinaryTreeNode<int>* root = helper(preorder, inorder, 0, inLength - 1, 0, preLength - 1);
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
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printEachLevelInNewLine(root);
}