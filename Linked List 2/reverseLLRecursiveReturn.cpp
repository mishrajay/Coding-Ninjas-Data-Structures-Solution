#include<iostream>
using namespace std;
//#include"linkedList.cpp"
#include"takeInputInLLBetter.cpp"

Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    if(head == NULL || head -> next == NULL){
        return head; 
    }
    Node *smallHead = reverseLinkedListRec(head -> next);
    Node *temp = smallHead;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = head;
    head -> next = NULL;
    
    return smallHead;
}
int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Node *head = takeInputBetter();
		head = reverseLinkedListRec(head);
		print(head);
	}

	return 0;
}