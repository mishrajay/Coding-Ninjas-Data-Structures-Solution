/*Given a generic tree, find and return the node for which sum of its data and data of 
all its child nodes is maximum. In the sum, data of the node and data of its immediate 
child nodes has to be taken.
Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The order is: data for root node, number of children to root node, data of each of 
child nodes and so on and so forth for each node. The data of the nodes of the tree is 
separated by space. 
Output format :
The first and only line of output contains the data of the node with maximum sum, 
as described in the task.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1
*/
#include<iostream>
using namespace std;
#include"treeNodeUse.cpp"

//first is the node whose sum with children sum is max
//second is the sum of root data and children data
pair<TreeNode<int>*, int> helper(TreeNode<int>* root){
    pair<TreeNode<int>*, int> output;
    if(root == NULL){
        output.first = NULL;
        output.second = 0;
        return output;
    }

    int sum = root -> data;
    for(int i = 0; i < root -> children.size(); i++){
        sum += root -> children[i] -> data;
    }

    output.first = root;
    output.second = sum;

    for(int i = 0; i < root -> children.size(); i++){
        pair<TreeNode<int>* , int> smallTree = helper(root -> children[i]);
        if(smallTree.second > output.second){
            output.first = smallTree.first;
            output.second = smallTree.second;
        }
    }

    return output;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    return helper(root).first;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}