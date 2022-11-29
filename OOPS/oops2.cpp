#include<iostream>
using namespace std;
#include"oops1.cpp"

int main(){
    student s1;
    student *s2 = new student;
    //s1.age = 10; we cannot write this coz age is a private member
    s1.setAge(10,123);
    s1.display();
    s2 -> setAge(20,1234);
    s2 -> display();
    //we can also use getAge fn instead of display.
    delete s2;
}