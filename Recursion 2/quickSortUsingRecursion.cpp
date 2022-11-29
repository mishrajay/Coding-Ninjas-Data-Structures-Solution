#include <iostream>
using namespace std;

void swap(int *input, int a, int b){
    int temp = input[a];
    input[a] = input[b];
    input[b] = temp;
}

int partition(int *input, int si, int ei){
    if(si >= ei){
        return 0;
    }
    int count = 0;
    for(int i = si; i <= ei; i++){
        if(input[i] < input[si]){
            count++;
        }
    }
    swap(input, si, si + count);
    int i = si, j = ei;
    int y = si + count;
    while(i < y && j >= y){
        if(input[i] < input[y]){
            i++;
        }
        else if(input [j] >= input[y]){
            j--;
        }
        else{
            swap(input, i, j);
            i++;
            j--;
        }
    }
    return si + count;
}

void quickSort(int *input, int start, int end){
    if(start >= end){
        return;
    }
    int x = partition(input, start, end);
    quickSort(input, start, x - 1);
    quickSort(input, x + 1, end);

}

void quickSort(int *input, int size){
    if(size==0 || size==1){
        return;
    }
    quickSort(input, 0, size - 1);
}

int main(){
    int n;
    cin>>n;
    int *input = new int[n];
    for(int i = 0; i < n; i++){
        cin>>input[i];
    }
    quickSort(input, n);
    for(int i = 0; i < n; i++){
        cout<<input[i]<<" ";
    }
    delete [] input;
}