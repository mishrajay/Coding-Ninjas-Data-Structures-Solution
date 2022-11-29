#include<iostream>
using namespace std;

void allIndices(int input[], int currIndex, int size, int x, int output[], int &k){
    if(currIndex==size){
        return;
    }

    if(input[currIndex]==x){
        output[k] = currIndex;
        k++;
    }

    allIndices(input, currIndex + 1, size, x, output, k);
}

int allIndices(int input[], int size, int x, int output[]){
    int k = 0;
    allIndices(input, 0, size, x, output, k);
    return k;
}

int main(){
    int size;
    cin>>size;
    int *input = new int[size];
    for(int i = 0; i < size; i++){
        cin>>input[i];
    }
    int x;
    cin>>x;

    int *output = new int[size];

    int outputSize = allIndices(input, size, x, output);

    for(int i = 0; i < outputSize; i++){
        cout<<output[i]<<" ";
    }

    delete[] input;
    delete[] output;
}