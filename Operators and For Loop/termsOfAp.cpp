#include<iostream>
using namespace std;

int main() {
	// Write your code here
	// int x,n,i,count=0;
    // cin>>x;
    // for(n=1;n>0;n++){
    //     i=3*n+2;
    //     if(i%4!=0){
    //         cout<<i<<" ";
    //         count++;
    //     }
    //      if(count=x){
    //         break;
    //     }
    // }
    int n,count,i,j;
    cin>>n;
    count=1;
    j=1;
    while(count<=n){
        i=3*j+2;
        if(i%4==0){
            j++;
            continue;
        }
        else{
            cout<<i<<" ";
            count++;
            j++;
        }

    }
}
