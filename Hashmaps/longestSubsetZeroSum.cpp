/*
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format
The first and only line of output contains length of the longest subarray whose sum is zero.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1:
10 
95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output 1:
5
Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897 
Sample Input 2:
5
2 -2 0 -2 2
Sample Output 2:
5
Sample Input 3:
6
1 2 3 4 -10 10
Sample Output 3:
5
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int *arr, int size){
    unordered_map<int, int> m;
    int sum = 0, length = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];

        if(sum == 0){
            length = i + 1;
        }

        if(m.count(sum) > 0){
            length = max(length, i - m[sum]);
        }
        else{
            m[sum] = i;
        }
    }
    return length;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}