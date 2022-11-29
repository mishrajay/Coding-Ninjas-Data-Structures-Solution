#include<iostream>
using namespace std;
#include"linkedList.cpp"
#include"takeInputInLLBetter.cpp"

Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    if(head == NULL){
        return head;
    }
    if(pos == 0){
        Node *temp = head;
        head = head -> next;
        delete temp; 
        return head;
    }
    
    if(head != NULL){
    	Node *smallHead = deleteNodeRec(head -> next, pos - 1);
    	head -> next = smallHead;
    }
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeInputBetter();
		int pos;
		cin >> pos;
		head = deleteNodeRec(head, pos);
		print(head);
	}

	return 0;
}