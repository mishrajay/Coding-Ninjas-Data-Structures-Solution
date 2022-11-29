#include<iostream>
using namespace std;
#include "staticMembers.cpp"

int main(){
    student s1;

    student s2,s3,s4;

    student *s5 = new student;

    cout << student :: getTotalStudents();
}