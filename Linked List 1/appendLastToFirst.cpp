#include<iostream>
using namespace std;
#include"linkedList.cpp"
#include"takeInputInLLBetter.cpp"

/*You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space. 

The second line contains the integer value 'N'. It denotes the number of nodes to be moved from last to the front of the singly linked list.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
Output format :
For each test case/query, print the resulting singly linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
0 <= N < M
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Sample Input 1 :
2
1 2 3 4 5 -1
3
10 20 30 40 50 60 -1
5
Sample Output 1 :
3 4 5 1 2
20 30 40 50 60 10
Sample Input 2 :
1
10 6 77 90 61 67 100  -1
4
Sample Output 2 :
90 61 67 100 10 6 77 
 Explanation to Sample Input 2 :
We have been required to move the last 4 nodes to the front of the list. Here, "90->61->67->100" is the list which represents the last 4 nodes. When we move this list to the front then the remaining part of the initial list which is, "10->6->77" is attached after 100. Hence, the new list formed with an updated head pointing to 90.
*/
Node *appendLastNToFirst(Node *head, int n){
    if(head == NULL || n == 0){
        return head;
    }
    Node *fast = head;
    Node *slow = head;
    for(int i = 0; i < n; i++){
        fast = fast -> next;
    }
    while(fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next;
    }
    Node *start = slow -> next;
    slow -> next = NULL;
    fast -> next = head;
    head = start;
    
    return head;
}

// **********************************OR*************************************
// Node* appendLastNToFirst(Node* head, int n){
//     if(head == NULL){
//         return head;
//     }

//     int count = 1;
//     Node* currNode = head;
//     while(currNode -> next != NULL){
//         currNode = currNode -> next;
//         count++;
//     }

//     currNode -> next = head;
//     int x = count - n;
//     Node* prev = NULL, *curr = head;
//     while(x--){
//         prev = curr;
//         curr = curr -> next;
//     }

//     prev -> next = NULL;
//     head = curr;
//     return head;

// }

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