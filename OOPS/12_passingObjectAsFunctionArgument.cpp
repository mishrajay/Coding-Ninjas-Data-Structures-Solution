#include<iostream>
using namespace std;

class complex{
    int a,b;
    
    public :
    void setData(int x, int y){
        a=x;
        b=y;
    }

    void setDataBySum(complex o1, complex o2) //here we passed objects o1,o2 as function arguments 
                                              //and have to write class name before object name
   
    {
        a= o1.a + o2.a;//o1,o2 are the objects
        b= o1.b + o2.b;
    
    }

    void printNumber (){
        cout<<"your complex number is "<<a<<" + i"<<b<<endl;;
    }
};

int main(){
    complex c1,c2,c3;
    c1.setData(1,2);
    c1.printNumber();

    c2.setData(3,4);
    c2.printNumber();

    c3.setDataBySum(c1,c2);
    c3.printNumber();

    return 0;
}
