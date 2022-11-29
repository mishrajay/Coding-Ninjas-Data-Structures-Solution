#include<iostream>
using namespace std;
#include"linkedList.cpp"
#include"takeInputInLLBetter.cpp"

int length(Node *head) {
    // Write your code here
    if(head == NULL){
        return 0;
    }
    
    int smallOutput = length(head -> next);
    return smallOutput + 1;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        Node *head = takeInputBetter();
        cout << length(head) << "\n";
    }
}