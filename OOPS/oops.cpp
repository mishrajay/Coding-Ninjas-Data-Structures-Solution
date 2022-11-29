#include<iostream>
using namespace std;
#include"student.cpp"//here we included student.cpp file,check what's written there.
int main(){
    //static allocation of objects.
    stud s1;
    stud s2,s3,s4;
    s1.rollNo = 10;//rollNo of object s1 = 10;
    cout<<s1.rollNo<<endl;

    //dynamic allocation of objects.
    stud *s5 = new stud;//stud is user defined data type here.
    (*s5).rollNo = 20;
    cout<<(*s5).rollNo<<endl;//use deference in dynamic alocation

    s5 -> rollNo = 30;//can also write like this but only in dynamic allocation
    cout<<s5 -> rollNo<<endl;
    delete s5;
}
