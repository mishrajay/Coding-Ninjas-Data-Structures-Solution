#include<iostream>
using namespace std;

void mergeSort(int *input, int size, int si, int mid, int ei){
    int *tempArr = new int[size];
    int i = si, j = mid + 1, k = 0;
    while(i <= mid && j <= ei){
        if(input[i] < input[j]){
            tempArr[k] = input[i];
            i++;
            k++;
        }
        else{
            tempArr[k] = input[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        tempArr[k] = input[i];
        i++;
        k++;
    }
    while(j <= ei){
        tempArr[k] = input[j];
        j++;
        k++;
    }
    int x = 0;
    for(int i = si; i <= ei; i++){
        input [i] = tempArr[x];
        x++;
    }
    delete [] tempArr;
}

void mergeSort(int *input, int size, int si, int ei){
    if(si>=ei){
        return;
    }
    int mid = (si + ei) / 2;
    mergeSort(input, size, si, mid);
    mergeSort(input, size, mid + 1, ei);
    mergeSort(input, size, si, mid, ei);
}

void mergeSort(int *input, int size){
    if(size==0 || size==1){
        return;
    }
    mergeSort(input, size, 0, size - 1);
}

int main(){
    int n;
    cin>>n;
    int *input = new int[n];
    for(int i = 0; i < n; i++){
        cin>>input[i];
    }
    mergeSort(input, n);
    for(int i = 0; i < n; i++){
        cout<<input[i]<<" ";
    }
    delete [] input;
}