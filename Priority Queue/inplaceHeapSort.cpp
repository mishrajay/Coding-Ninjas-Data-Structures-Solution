#include <iostream>
using namespace std;
//this prg sorts in descending order
void heapSort(int arr[], int n) {
    //creating heap from the input array
	//creating heap means to arrange the elements acc to min order property or max order 
    //for descending order, use min order property
    //for ascending order, use max order property
    for(int i = 1; i < n; i++){
        int childIndex = i;
        while(childIndex > 0){
        	int parentIndex = (childIndex - 1) / 2;
    		 
            if(arr[parentIndex] > arr[childIndex]){
            	int temp = arr[childIndex];
            	arr[childIndex] = arr[parentIndex];
            	arr[parentIndex] = temp;
        	}  
        	else{
            	break;
        	}
        
        	childIndex = parentIndex;
        }
        
    }
    
    //arranging the elements in descending order
    int size = n;
    while(size > 1){
    	int temp1 = arr[0];
    	arr[0] = arr[size - 1];
    	arr[size - 1] = temp1;
    	size--;
    	int parentIndex = 0;
    	int leftChildIndex = 2 * parentIndex + 1;
    	int rightChildIndex = 2 * parentIndex + 2;
    
        while(leftChildIndex < size){
            
        	int minIndex = parentIndex;
        	if(arr[leftChildIndex] < arr[minIndex]){
            	minIndex = leftChildIndex;
        	}
        
	        if(arr[rightChildIndex] < arr[minIndex] && rightChildIndex < size){
    	        minIndex = rightChildIndex;
        	}
        
        	if(minIndex == parentIndex){
            	break;
       		}
        
            int temp = arr[minIndex];
        	arr[minIndex] = arr[parentIndex];
        	arr[parentIndex] = temp;
            
            parentIndex = minIndex; 
        	leftChildIndex = 2 * parentIndex + 1;
    		rightChildIndex = 2 * parentIndex + 2;
        }
         
    }
    
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}