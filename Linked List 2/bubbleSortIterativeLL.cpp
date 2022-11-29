#include<iostream>
using namespace std;
//#include"linkedList.cpp"
#include"takeInputInLLBetter.cpp"
Node *bubbleSort(Node *head)
{
	// Write your code here
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    Node * curr=head;
    while(curr->next!=NULL)
    {
        Node *p=head;
        while(p->next!=NULL)
        {
            if(p->data>p->next->data)
            {
                int t=p->data;
                p->data=p->next->data;
                p->next->data=t;
            }
            p=p->next;
        }
        curr=curr->next;
    }
    
    return head;
}
int main()
{
	Node *head = takeInputBetter();
	head = bubbleSort(head);
	print(head);
}