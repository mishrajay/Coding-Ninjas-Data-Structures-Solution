#include <iostream>
using namespace std;

class c2;

class c1{
    int a;
    friend void swap(c1 &, c2 &);
    public:
    void setData(int x){
        a=x;
    }
    void display(){
        cout<<a<<endl;
    }
};

class c2{
    int b;
    friend void swap(c1 &, c2 &);
    public:
    void setData(int y){
        b=y;
    }
    void display(){
        cout<<b<<endl;
    }
};

void swap (c1 & o1, c2 & o2)//& is given for reference
{
    int temp = o1.a;
    o1.a = o2.b;
    o2.b = temp;
    
}

int main(){
    c1 o1;
    o1.setData(50);
    c2 o2;
    o2.setData(100);
    swap(o1, o2);
    cout<<"the value of a after swapping= ";
    o1.display();//this should be written in the next line after cout
    cout<<"the value of b after swapping= ";
    o2.display();
    return 0;
}