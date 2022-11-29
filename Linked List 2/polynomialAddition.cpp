#include <iostream>
#include<climits>
using namespace std;

class Node
{
public:
    int coeff;
    int exp;
    Node *next;

    Node(int coeff, int exp)
    {
        this->coeff = coeff;
        this->exp = exp;
        next = NULL;
    }
};

Node *creation()
{
    Node *head = NULL;
    Node *tail = NULL;
    int coeff, exp;
    cin >> coeff >> exp;
    while (coeff != -1 && exp != -1)
    {
        Node *newNode = new Node(coeff, exp);
        if (head == NULL || tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> coeff >> exp;
    }
    return head;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->coeff << "x^" << temp->exp;
        temp = temp->next;
        if (temp != NULL)
        {
            cout << " + ";
        }
    }
    cout << endl;
}

void addition(Node *head1, Node *head2)
{
    int count = 0;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 != NULL)
    {
        temp2 = head2;
        while (temp2 != NULL)
        {   count = 0;
            if (temp1->exp == temp2->exp)
            {   count++;
                cout << temp1->coeff + temp2->coeff << "x^" << temp1->exp<<" + ";
                temp2 -> coeff = INT_MIN;
                break;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        if(count == 0){
            cout << temp1->coeff << "x^" << temp1->exp<<" + ";
        }
        temp1 = temp1 -> next;
    }
    Node *temp = head2;
    while(temp != NULL){
        if(temp -> coeff != INT_MIN){
            cout << temp->coeff << "x^" << temp->exp;
        }
        temp = temp -> next;
        if(temp -> coeff != INT_MIN && temp != NULL){
            cout << " + ";
        }
    }
}

int main()
{
    Node *head1 = creation();
    Node *head2 = creation();

    display(head1);
    display(head2);

    cout<<"addition of polynomials is : "<<endl;
    addition(head1, head2);
}