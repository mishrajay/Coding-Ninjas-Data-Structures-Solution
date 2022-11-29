#include<iostream>
using namespace std;
#include"templates.cpp"

int main(){
    Pair<int, double> s1;
    s1.setX(100);
    s1.setY(200.45);
    cout<<s1.getX()<<" "<<s1.getY()<<endl;

    Pair<Pair<int, double>, double> s2;
    s2.setY(30.565);
    Pair<int, double> s3;
    s3.setX(10);
    s3.setY(20.786);
    s2.setX(s3);

    cout<<s2.getX().getX()<<" "<<s2.getX().getY()<<" "<<s2.getY()<<endl;

}