#include<iostream>
using namespace std;
#include <climits>
#include<cmath>

int main(){
    
    // Write your code here
    int a[100];
    int n,i,sec_large,large;
    cin>>n;
    for(i=0;i<n;i++){
        cin >> a[i];
        
    }
    //if we initialise large with a[0] and the given array elements contain negative number
    //we would not be able to find the largest number.
    //to resolve this issue, we will initialise lage and sec_large as INT_MIN(-2^31), 
    //which is the smallest negative number.
    //now if we compare large will be smaller than the current element in negative element 
    //array and same applies to sec_large.
    //to access INT_MIN we need to give a header file <climits>
    large=INT_MIN;
    for(i=0;i<n;i++){
        if(large<a[i]){
            large=a[i];
        }
    }
    
    sec_large=INT_MIN;
    for(i=0;i<n;i++){
        if(large!=a[i] && sec_large<a[i]){
            sec_large=a[i];
        }
    }
    cout<<sec_large;
}
