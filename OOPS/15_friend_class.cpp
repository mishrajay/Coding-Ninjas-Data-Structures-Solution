#include <iostream>
using namespace std;

class c2;

class c1{
    int a;
    friend void sum(c1, c2);
    public:
    void setData(int x){
        a=x;
    }
};

class c2{
    int b;
    friend void sum(c1, c2);
    public:
    void setData(int y){
        b=y;
    }
};

void sum(c1 o1, c2 o2){
    cout<<"the sum is "<<(o1.a + o2.b);
}

int main(){
    c1 o1;
    o1.setData(5);
    c2 o2;
    o2.setData(10);
    sum (o1,o2);
    return 0;
}