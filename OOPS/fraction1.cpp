#include<iostream>>
using namespace std;
#include"fraction.cpp"
//ques is to add the fractions f1 and f2 and store the result in f1 ie, f1 = f1 + f2 and print
int main(){
    fraction f1(10,2);
    fraction f2(15,4);

    f1.add(f2);

    f1.print();
    f2.print();
}