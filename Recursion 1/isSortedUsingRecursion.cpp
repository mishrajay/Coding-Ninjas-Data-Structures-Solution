#include <iostream>
using namespace std;

bool isSorted(int *input, int n){
    if(n==0 || n==1){
        return true;
    }
    if(input[0] > input[1]){
        return false;
    }

    bool isSmallerSorted = isSorted(input + 1, n - 1);
    return isSmallerSorted;
    
    /*if(isSmallerSorted){
        return true;
    }
    else{
        return false;
    }*/
}

int main(){
    int n;
    cin>>n;
    int *input = new int[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    if(isSorted(input, n)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    delete[]input;
}