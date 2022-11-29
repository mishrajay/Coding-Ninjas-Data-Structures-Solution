#include<iostream>
using namespace std;

class student{
    public :
    int rollNo;

    private :
    int age;

    public :
    //default constructor
    student(){
        cout<<"this is default constructor "<<endl;
    }


    //paramerterised constructor
    //once we create paramerterised constructor, we need to explicitly create 
    //default constructor
    student(int rollNo){
        cout<<"this is constructor 1 :"<<endl;
        this -> rollNo = rollNo;
    }

    student(int age, int rollNo){
        cout<<"this is constructor 2 :"<<endl;
        this -> age = age;
        this -> rollNo = rollNo;
    }

    void display(){
        cout<<"age = "<<age<<" rollNo = "<<rollNo<<endl;
    }
};