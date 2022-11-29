#include<iostream>
using namespace std;
#include "copyConstructor.cpp"

int main(){
    char name[] = "abcd";
    student s1(10,name);
    s1.display();
    
    student s2(s1);
    s2.name[0] = 'x';
    
    s2.display();
    s1.display();
}