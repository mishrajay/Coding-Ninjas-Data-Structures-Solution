#include<iostream>
using namespace std;
#include"linkedList.cpp"
#include"takeInputInLLBetter.cpp"

Node* insertNode(Node *head, int i, int data) {
	// Write your code here
    if(i == 0){
        Node *newData = new Node(data);
        newData -> next = head;
        head = newData;
        return head;
    }
    if(head != NULL){
    	Node *temp = insertNode(head -> next, i - 1, data);
    	head -> next = temp;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeInputBetter();
        int pos, data;
        cin >> pos >> data;
        head = insertNode(head, pos, data);
        print(head);
    }
}