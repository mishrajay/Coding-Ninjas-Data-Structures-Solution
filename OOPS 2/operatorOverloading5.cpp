#include<iostream>
using namespace std;
#include "operatorOverloading4.cpp"

int main(){
    fraction f1(10, 2);
    fraction f2 = f1++;
    //(f1++)++  nesting of post-increment operator is not allowed.
    f1.print();
    f2.print();

    fraction f3(10, 3);
    fraction f4(20, 4);
    (f3 += f4) += f4;
    f3.print();
    f4.print();
}