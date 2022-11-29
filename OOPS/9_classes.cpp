#include <iostream>
using namespace std;

class Employee{
    private ://private items can only be accessed by the functions made inside class 
    int a,b,c;
    public :
    int d,e;

    void setData(int x, int y,int z);//declaration
    void getData(){
        cout<<"The value of a="<<a<<endl;
        cout<<"The value of b="<<b<<endl;
        cout<<"The value of c="<<c<<endl;
        cout<<"The value of d="<<d<<endl;
        cout<<"The value of e="<<e<<endl;
    }
};

void Employee :: setData(int x, int y, int z){
    //::is the scope resolution operator
    a=x;
    b=y;
    c=z;
}

int main(){
    Employee tommy;//here, we have made tommay an object of class Employee
    tommy.d=67;
    tommy.e=89;
    tommy.setData(10,20,30);
    tommy.getData();
    //tommy.a=60; cannot run in the prg coz a is private and cannot be accessed directly 
    //it can only be accessed by any function of class
    return 0;
}