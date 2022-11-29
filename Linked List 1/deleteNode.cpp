#include<iostream>
using namespace std;
#include"linkedList.cpp"
#include"takeInputInLLBetter.cpp"

Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    Node *temp = head;
    int count = 0;
    if(head == NULL){
        return head;
    }
    if(pos == 0){
        head = head -> next;
        return head;
    }
    while(temp != NULL && count < pos - 1){
        temp = temp -> next;
        count++;
    }
    if(temp == NULL){
        return head;
    }
    if(temp -> next == NULL){
        return head;
    }
        
    Node *a = temp -> next;
    temp -> next = a -> next;
    delete a;
    
    return head;
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
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}