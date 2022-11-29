#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n,rem,pv=1;// pv = place value
    long binary=0;
    cin>>n;
    while(n>0){
       rem= n%2;
       binary=binary+rem*pv;
       n=n/2;
       pv=pv*10;
    }
    cout<<binary;
}
