#include<bits/stdc++.h>
using namespace std;

void kSortedArray(int arr[], int n, int k){
    priority_queue<int> p;
    for(int i = 0; i < k; i++){
        p.push(arr[i]);
    }

    int j = 0;
    for(int i = k; i < n; i++){
        arr[j++] = p.top();
        p.pop();
        p.push(arr[i]);
    }

    while(!p.empty()){
        arr[j++] = p.top();
        p.pop();
    }
}

int main(){
    int arr[] = {10, 15, 7, 6, 9};//given array should be k-sorted array
    kSortedArray(arr, 5, 3);
    for(int i = 0; i < 5; i++){
        cout<<arr[i]<<" ";
    }
}