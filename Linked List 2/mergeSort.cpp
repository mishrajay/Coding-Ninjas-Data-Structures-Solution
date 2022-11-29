#include<iostream>
using namespace std;
//#include"linkedList.cpp"
#include"takeInputInLLBetter.cpp"

Node *findMid(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    Node *head = NULL, *tail = NULL;
    if (head1->data < head2->data)
    {
        head = head1;
        tail = head1;
        head1 = head1->next;
    }
    else
    {
        head = head2;
        tail = head2;
        head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }
    if (head1 != NULL)
    {
        tail->next = head1;
    }
    if (head2 != NULL)
    {
        tail->next = head2;
    }
    return head;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = findMid(head);
    Node *half1 = head;
    Node *half2 = mid->next;
    mid->next = NULL;		//to divide the list further and further until it can no more be divided
    Node* head1 = mergeSort(half1);
    Node* head2 = mergeSort(half2);

    Node *finalHead = merge(head1, head2);
    return finalHead;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeInputBetter();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}