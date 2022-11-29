#include<iostream>
using namespace std;

int sum(int *a, int n, int s){
    if(n == 0){
        return s;
    }

    s = a[0] + sum(a+1, n - 1, s);
    return s;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    cout<<sum(a, n, 0);
}