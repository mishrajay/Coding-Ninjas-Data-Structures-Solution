#include<iostream>
#include<string>
using namespace std;

void pk(int num, string output){
    if(num==0){
        cout<<output<<" ";
        return;
    }
    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string smallAns = mapping[num % 10];
    for(int i = 0; i < smallAns.size(); i++){
        pk(num / 10, smallAns[i] + output);
    }
}

void printKeypad(int num){
    pk(num, "");
}

int main(){
    int num;
    cin>>num;
    printKeypad(num);
}