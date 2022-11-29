#include<iostream>
using namespace std;

int main(){
    /* Read input as specified in the question.
     * Print output as specified in the question.
     */
    int n,i,sum=0;
    cin>>n;
    
    int a[100];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    
    for(i=0;i<n;i++){
        sum=sum+a[i];
    }
    
    cout<<sum;
}
