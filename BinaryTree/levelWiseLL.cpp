/*Given a binary tree, write code to create a separate linked list for each level.
You need to return the array which contains head of each level linked list.
Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The data of the nodes of the tree is separated by space. If any node does not have 
left or right child, take -1 in its place. Since -1 is used as an indication whether 
the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
Each level linked list is printed in new line (elements are separated by space).
Constraints:
Time Limit: 1 second
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5 
6 10 
2 3 
9
*/
#include<iostream>
using namespace std;
#include"binaryTreeNodeUse.cpp"
#include"Node.cpp"
#include<queue>
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL){
        vector<Node<int>*> output;
        output.push_back(NULL);
        return output;
    }
    vector<Node<int>*> output;
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    queue<BinaryTreeNode<int>*> p;
    p.push(root);
    p.push(NULL);
    
    while(!p.empty()){
        BinaryTreeNode<int>* front = p.front();
        p.pop();
        if(front){
            Node<int>* newNode = new Node<int>(front -> data);
        	if(head == NULL){
            	head = newNode;
            	tail = newNode;
        	}
        	else{
            	tail -> next = newNode;
            	tail = newNode;
        	}

            if(front -> left != NULL){
                p.push(front -> left);    
            }
            if(front -> right != NULL){
                p.push(front -> right);  
            }
        }
        else{
            output.push_back(head);
            head = NULL;
            tail = NULL;
            if(p.empty()){
                break;
            }
            p.push(NULL);                
        }
    }
    return output;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    BinaryTreeNode<int> *root = takeInputLevelWise();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}