#include<iostream>
using namespace std;
//#include"linkedList.cpp"
#include"takeInputInLLBetter.cpp"

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if(head1 == NULL){
    	return head2;
    }
    if(head2 == NULL){
    	return head1;
    }
    if(head1 -> data < head2 -> data){
    	head1 -> next = mergeTwoSortedLinkedLists(head1 -> next, head2);
    	return head1;
    }
    else{
    	head2 -> next = mergeTwoSortedLinkedLists(head1, head2 -> next);
    	return head2;
    }
}
/*
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    Node *newHead = NULL;
    Node *newTail = NULL;
    if(head1->data < head2->data)
        {
            newHead=head1;
            newTail=head1;
            head1=head1->next;
        }
        else
        {
            newHead=head2;
            newTail=head2;
            head2=head2->next;
        }
    
    
    while(head1 != NULL && head2 != NULL){
        if(head1 -> data < head2 -> data){
            newTail -> next = head1;
            newTail = newTail->next;
            head1 = head1 -> next;
        }
        else{
            newTail -> next = head2;
            newTail = newTail->next;
            head2 = head2 -> next;
        }
    }
    if(head1 != NULL){
        newTail -> next = head1;
    }
    if(head2 != NULL){
        newTail -> next = head2;  
    }
    
    return newHead;
}*/

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeInputBetter();
		Node *head2 = takeInputBetter();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}