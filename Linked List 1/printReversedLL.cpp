#include<iostream>
using namespace std;
//#include"linkedList.cpp"
#include"takeInputInLLBetter.cpp"

void printReverse(Node *head)
{
    //Write your code here
    if(head == NULL){
        return;
    }
    
    printReverse(head -> next);
    cout<<head -> data<<" ";
} 

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeInputBetter();
		printReverse(head);
		cout << endl;
	}
	return 0;
}