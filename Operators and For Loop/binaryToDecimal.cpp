/*
Given a binary number as an integer N, convert it into decimal and print.
Input format :
An integer N in the Binary Format
Output format :
Corresponding Decimal number (as integer)
Constraints :
0 <= N <= 10^9
Sample Input 1 :
1100
Sample Output 1 :
12
Sample Input 2 :
111
Sample Output 2 :
7
*/

#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n,rem,base=1,decimal=0;
    cin>>n;
    while(n>0){
        rem=n%10;
        decimal=decimal+rem*base;
        n=n/10;
        base=base*2;
    }
    cout<<decimal;
}


#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n,rem,base=1,decimal=0;
    cin>>n;
    while(n>0){
        rem=n%10;
        decimal=decimal+rem*base;
        n=n/10;
        base=base*2;
    }
    cout<<decimal;
}