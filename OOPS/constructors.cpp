#include<iostream>
using namespace std;
#include"constructors1.cpp"
int main(){
    student s1;

    student s2(10,1001);
    s2.display();

    student *s3 = new student(20);
    s3 -> display();


}