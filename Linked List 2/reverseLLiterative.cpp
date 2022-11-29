#include<iostream>
using namespace std;
//#include"linkedList.cpp"
#include"takeInputInLLBetter.cpp"

Node *reverseLinkedList(Node *head) {
    // Write your code here
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node *prevNode = NULL, *currNode = head;
    while(currNode != NULL){
        Node *nextNode = currNode -> next;
        currNode -> next = prevNode;	//address of prevNode node is now stored in the next of currNode
        prevNode = currNode;
        currNode = nextNode;
    }
    
    head = prevNode;
    return head;
    
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeInputBetter();
        head = reverseLinkedList(head);
        print(head);
    }

    return 0;
}