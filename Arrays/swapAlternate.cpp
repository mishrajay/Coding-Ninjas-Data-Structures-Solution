#include<iostream>
using namespace std;
//swap the alternate array element --:

void inputArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void swapAlternateArray(int arr[], int n){
    int i,j,temp;
    i=0,j=1;
    while(j<n){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i+=2;
        j+=2;
    }
}

void printArray(int arr[], int n){
    for(int k=0;k<n;k++){
        cout<<arr[k]<< " ";
    }
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[10];
        cout<<"input array :"<<endl;
        inputArray(arr, n);
        
        swapAlternateArray(arr, n);

        cout<<"swapped array :"<<endl;
        printArray(arr, n);
        
    }
}