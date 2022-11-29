#include<iostream>
using namespace std;
#include "linkedList.cpp"

//printing a linked list
void print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    Node n1(10);
    Node n2(20);
    Node n3(30);
    Node n4(40);
    Node n5(50);

    Node *head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;//now all the elements are linked to each other as they contain the address
                  //of next node

    print(head);
    print(head);//here, head will initialise to zero coz in the first call the copy that 
                //print fn made of head, that head became zero not the copy that main fn 
                //have of head so, linked list will be printed twice.
}