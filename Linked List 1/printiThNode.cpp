#include<iostream>
using namespace std;
//#include"linkedList.cpp"
#include"takeInputInLLBetter.cpp"

void printIthNode(Node *head, int i)
{
    //Write your code here
    int count = 0;
    while(head != NULL){
        if(count == i){
            cout<<head -> data;
        }
        count++;
        head = head -> next;
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
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}