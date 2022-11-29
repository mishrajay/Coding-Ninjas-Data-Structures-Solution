#include<iostream>
using namespace std;


int main(){
    //Write your code here. 
    int n;
    cin>>n;
    int a=1,b=1;
    int c;
    if(n==1 || n==2){
            c=1;
        }
    for(int i=1;i<n-1;i++){
        
      c=a+b;
      a=b;
      b=c;
    }
    cout<<c;
}
