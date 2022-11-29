/*
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.
Input Format:
The first line of input contains an integer, that denotes value of k.
The following lines of input represent k sorted arrays. Each sorted array uses two lines of input. The first line contains an integer, that denotes the size of the array. The following line contains elements of the array.
Output Format:
The first and only line of output contains space separated elements of the merged and sorted array, as described in the task.
Constraints:
0 <= k <= 1000
0 <= n1, n2 <= 10000
Time Limit: 1 second
Sample Input 1:
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1:
0 1 2 5 6 9 45 78 90 100 234
*/

#include<bits/stdc++.h>
using namespace std;
/*
Time Complexity: O(K * N * log(k * N))
Space Complexity: O(K * N)
where K is the number of arrays to merge and
N is the average length of the arrays
*/
vector<int> mergeKsortedArrays(vector<vector<int>*> input){
    priority_queue<int, vector<int>, greater<int>> p;
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i] -> size(); j++){
            p.push(input[i] -> at(j));
        }
    }

    vector<int> output;
    while(!p.empty()){
        output.push_back(p.top());
        p.pop();
    }

    return output;
}

int main(){
    int t;
    cin>>t;
    vector<vector<int>*> input;
    while(t--){
        int n;
        cin>>n;
        vector<int>* v = new vector<int>();
        for(int i = 0; i < n; i++){
            int a;
            cin>>a;
            v -> push_back(a);
        }
        input.push_back(v);
    }
    vector<int> output = mergeKsortedArrays(input);
    for(int i = 0; i < output.size(); i++){
        cout<<output[i]<<" ";
    }

}