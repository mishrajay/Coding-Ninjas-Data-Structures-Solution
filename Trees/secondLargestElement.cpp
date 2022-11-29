/*Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The order is: data for root node, number of children to root node, data of each of
child nodes and so on and so forth for each node. The data of the nodes of the tree 
is separated by space.
Output Format :
The first and only line of output contains data of the node with second largest data.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
*/
#include<iostream>
using namespace std;
#include"treeNodeUse.cpp"
#include<climits>
//first - largest and second - sec_largest
pair<TreeNode<int>*, TreeNode<int>*> helper(TreeNode<int>* root){
    TreeNode<int>* largest = root;
    TreeNode<int>* discarded = NULL;
    TreeNode<int>* sec_largest = NULL;
    
    for(int i = 0; i < root -> children.size(); i++){
        pair<TreeNode<int>*, TreeNode<int>*> child = helper(root -> children[i]);
        if(largest->data > child.first->data)
        {
            if(sec_largest==NULL)
                sec_largest = child.first;
            else if(sec_largest->data < child.first->data)
            {
                sec_largest = child.first;
            }
        }
        else if(largest->data < child.first->data)
        {
            discarded = largest;
            largest = child.first;
            if(child.second==NULL)
            {
				sec_largest = discarded;
            }
            else
            {
				if(child.second->data > discarded->data)
                    sec_largest = child.second;
                else
                    sec_largest = discarded;
            }
        }
        else
        {
            if(sec_largest==NULL && child.second!=NULL)
                sec_largest=child.second;
            else if(sec_largest!=NULL && child.second!=NULL)
            {
                if(sec_largest->data < child.second->data)
                    sec_largest = child.second;
            }
        }
        
    }  
    
    pair<TreeNode<int>*, TreeNode<int>*> p1;
    p1.first = largest;
    p1.second = sec_largest;
    return p1;
}


TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL){
        return NULL;
    }
    
    return helper(root).second;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}