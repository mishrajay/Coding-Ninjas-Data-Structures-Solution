/*Given a generic tree, print the post-order traversal of given tree.
The post-order traversal is: visit child nodes first and then root node.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains the elements printed in post-order traversal. The elements in the output must be separated by a single space.
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 400 50 0 0 0 0 
Sample Output 1:
400 50 20 30 40 10
*/
#include<iostream>
using namespace std;
#include"treeNodeUse.cpp"
//in postorder first the children data is printed then the root data is printed
void printPostOrder(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return;
    }
    
    //to print the children data
    if(root -> children.size() == 0){
        cout<<root -> data<<" ";
        return;
    }
    
    for(int  i = 0; i < root -> children.size(); i++){
        printPostOrder(root -> children[i]);
    }

    //to print the root data
    cout<<root -> data<<" ";
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printPostOrder(root);
}