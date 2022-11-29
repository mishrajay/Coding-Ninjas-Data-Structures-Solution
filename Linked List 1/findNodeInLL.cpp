#include<iostream>
using namespace std;
#include"linkedList.cpp"
#include"takeInputInLLBetter.cpp"

int findNode(Node *head, int n){
    // Write your code here.
    int count = 0;
    while(head != NULL){
        if(head -> data == n){
            return count;
        }
        head = head -> next;
        count++;
    }
    
    return -1;
    
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeInputBetter();
		int val;
		cin >> val;
		cout << findNode(head, val) << endl;
	}
}