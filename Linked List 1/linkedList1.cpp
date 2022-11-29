#include<iostream>
using namespace std;
#include "linkedList.cpp"

int main(){
    //creating objects statically
    Node n1(10);
    Node *head = &n1;   //head is a pointer of type node as it holds the address of next node
                        //head is not an object
    Node n2(20);

    n1.next = &n2;

    cout << head -> data << endl;

    //creating objects dynamically
    Node *n3 = new Node(30);
    Node *head1 = n3;

    Node *n4 = new Node(40);
    n3 -> next = n4;

    cout << head1 -> data << endl; 
    




}