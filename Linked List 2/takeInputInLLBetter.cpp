#include<iostream>
using namespace std;
class Node{
    public :
    int data;
    Node *next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node* takeInputBetter(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *newData = new Node(data);
        if(head == NULL){
            head = newData;
            tail = newData;
        }
        else{
            tail -> next = newData;
            tail = newData;
            //OR
            //tail = tail -> next;
        }

        cin>>data;
    }
    return head;
}

void print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
/*
int main(){
    Node *head = takeInputBetter();
    print(head);
    print(head);
}*/