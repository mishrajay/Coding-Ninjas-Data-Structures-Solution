#include<bits/stdc++.h>
using namespace std;

void kLargestElements(int *arr, int n, int k){
    priority_queue<int, vector<int>, greater<int>> p;//inbuilt min-priority queue
    for(int i = 0; i < k; i++){
        p.push(arr[i]);
    }

    for(int i = k; i < n; i++){
        if(p.top() < arr[i]){
            p.pop();
            p.push(arr[i]);
        }
    }

    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int k;//k is the no. of maximum elements that we want to find in the given array
    cin>>k;
    kLargestElements(arr, n, k);
    delete [] arr;
}