//sorting means to arrange the array elements in either ascending or descending order
#include <iostream>
using namespace std;
//in selection sort, we compare the smallest element in every round with the current element
//and if the latter is smaller than the former, we swap them.
//in selection sort, the smallest element reaches its correct position in every round 
//while in bubble sort, the largest element reaches its correct position in each round.

void bubbleSort(int *input, int size)
{
    //Write your code here
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1;j++){
            if(input[j]>input[j+1]){
                int temp=input[j];
                input[j]=input[j+1];
                input[j+1]=temp;
            }
        }
    }
}
int main()
{

	int t;
	cin >> t;

	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		bubbleSort(input, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}

		delete[] input;
		cout << endl;
	}
}