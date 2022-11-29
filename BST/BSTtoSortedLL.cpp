/*Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:
The first and only line of input contains data of the nodes of the tree in level 
order form. The data of the nodes of the tree is separated by space. If any node 
does not have left or right child, take -1 in its place. Since -1 is used as an 
indication whether the left or right nodes exist, therefore, it will not be a part 
of the data of any node.   
Output Format:
The first and only line of output prints the elements of sorted linked list.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10
*/
#include<iostream>
using namespace std;
#include"BSTheaderFile.cpp"
#include"Node.h"
//first is head and second is tail
pair<Node<int>*, Node<int>*> helper(BinaryTreeNode<int>* root){
    pair<Node<int>*, Node<int>*> p;
    if(root==NULL){
        p.first=NULL;
        p.second=NULL;
        return p;
    }
    Node<int> *temp = new Node<int>(root->data);
    
    pair<Node<int>*, Node<int>*> pl = helper(root->left);
    pair<Node<int>*, Node<int>*> pr = helper(root->right);
    if(pl.first==NULL){
        pl.first=temp;
        pl.second = temp;
    }
    else{
        pl.second->next=temp;
    }
    temp->next = pr.first;
    if(pr.first==NULL){
        p.first=pl.first;
        p.second=temp;
    }
    else{
        p.first=pl.first;
        p.second = pr.second;
    }
    return p;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    pair<Node<int> *, Node<int>*> p = helper(root);
    return p.first;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}