#include<iostream>
using namespace std;
#include"stackUsingTemplates.cpp"

int main(){
    stackUsingTemplates<char> s;
    s.push(100);    //numbers will be treated as ascii values
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    cout<<s.top()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.top()<<endl;

    cout<<s.size()<<endl;

    cout<<s.isEmpty()<<endl;
}