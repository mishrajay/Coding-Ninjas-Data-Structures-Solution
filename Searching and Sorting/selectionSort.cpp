//sorting means to arrange the array elements in either ascending or descending order
#include <iostream>
using namespace std;
//in selection sort, we compare the smallest element in every round with the current element
//and if the latter is smaller than the former, we swap them.
//in selection sort, the smallest element reaches its correct position in every round 
//while in bubble sort, the largest element reaches its correct position in each round.
void selectionSort(int arr[], int n){
    
    for(int i=0;i<n-1;i++){//i=no. of rounds, if n=6,no. of rounds=5 i.e,(0-4) or 0 to n-2
        //loop to find the min number
        int minIndex=i;
        int min=arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                minIndex=j;
            }
        }
        //swaping of min number with current element
        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}

int main(){
    int n;
    cin>>n;

    int arr[100];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    selectionSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}