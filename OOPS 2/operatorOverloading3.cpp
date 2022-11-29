#include<iostream>
using namespace std;
#include "operatorOverloading2.cpp"

int main(){
    fraction f1(10, 2);
    fraction f2 = ++(++f1);
    f1.print();
    f2.print();
}