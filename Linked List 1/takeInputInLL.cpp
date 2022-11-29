#include<iostream>
using namespace std;
#include "linkedList.cpp"

//when we input -1 the compiler will stop taking input, ie, -1 is our terminator.
//complexity of this prg is n^2, thus we've written improved prg in takeInputBetter prg.
Node* takeInput(){      //return type (head) is of type pointer.
    int data;
    cin>>data;
    Node *head = NULL;
    while(data != -1){
        Node *newData = new Node(data);//we need to create newData object dynamically coz 
        if(head == NULL){              //the scope is only within while loop and if we create
            head = newData;            //object statically, after every iteration the previous
        }                              // object will be lost and in dynamic allocation it'll
        else{                          //not be lost until we deallocate it explicitly.
            Node *temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newData;
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
    //to print data twice
    temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
}
/*
int main(){
    Node *head = takeInput();
    print(head);
}*/