#include<iostream>
using namespace std;
//#include"linkedList.cpp"
#include"takeInputInLLBetter.cpp"

Node *midPoint(Node *head)
{
    // Write your code here
    if(head == NULL){
        return head;
    }
    
    Node *slow = head;
    Node *fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL){//fast != NULL for odd length and other for even length
        	slow = slow -> next;
        	fast = fast -> next -> next;
    }
    
    return slow;   
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeInputBetter();
		Node *mid = midPoint(head);
		if (mid != NULL)
		{
			cout << mid->data;
		}
		cout << endl;
	}
	return 0;
}