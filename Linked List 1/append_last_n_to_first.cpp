#include<iostream>
#include"./LinkedList/takeInputInLLBetter.cpp"
using namespace std;

Node* appendLastNToFirst(Node* head, int n){
    if(head == NULL){
        return head;
    }

    int count = 1;
    Node* currNode = head;
    while(currNode -> next != NULL){
        currNode = currNode -> next;
        count++;
    }

    currNode -> next = head;
    int x = count - n;
    Node* prev = NULL, *curr = head;
    while(x--){
        prev = curr;
        curr = curr -> next;
    }

    prev -> next = NULL;
    head = curr;
    return head;

}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeInputBetter();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}