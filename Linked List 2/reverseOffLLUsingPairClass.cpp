#include<iostream>
using namespace std;
#include"takeInputInLLBetter.cpp"

pair<Node*, Node*> rev(Node *head){
    if(head == NULL || head -> next == NULL){
        pair<Node*, Node*> output;
        output.first = head;
        output.second = head;
        return output;
    }

    pair<Node*, Node*> temp = rev(head -> next);
    temp.second -> next = head;
    head -> next = NULL;

    pair<Node*, Node*> output;
    output.first = temp.first;
    output.second = head;
    return output;

}

Node* reverse(Node *head){
    if(head == NULL){
        return head;
    }
    return rev(head).first;
}

int main(){
    Node *head = takeInputBetter();
    Node* head1 = reverse(head);
    print(head1);
}