#include<iostream>
using namespace std;
//#include"linkedList.cpp"
#include"takeInputInLLBetter.cpp"

int length(Node *head)
{
    //Write your code here
    int count = 0;
    while(head != NULL){
        count++;
        head = head -> next;
    }
    return count;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeInputBetter();
		cout << length(head) << endl;
	}
	return 0;
}