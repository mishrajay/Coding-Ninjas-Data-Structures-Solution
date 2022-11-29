#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n,d,rem=0;
    cin>>n;
    d=0;
    while(n>0){
        d=n%10;
        rem=rem*10+d;
        n=n/10;
    }
    cout<<rem;
}
