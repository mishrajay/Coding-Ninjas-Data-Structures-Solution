#include<iostream>
using namespace std;
#include "shallowNdeepCopy.cpp"

int main(){
    char name[] = "abcd";
    student s1(10,name);
    s1.display();
    
    name[0] = 'x';
    student s2(20,name);
    s2.display();

    s1.display();
}