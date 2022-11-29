#include<iostream>
using namespace std;
//#include"linkedList.cpp"
#include"takeInputInLLBetter.cpp"

int findNodeRec(Node *head, int n)
{
	//Write your code here
    if(head == NULL){
        return -1;
    }
    if(head -> data == n){
        return 0;
    }
    
    int smallOutput = findNodeRec(head -> next, n);
	if(smallOutput == -1){
        return -1;
    }
    else{
        return smallOutput + 1;
    }
        
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
		cout << findNodeRec(head, val) << endl;
	}
}