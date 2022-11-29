/*
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
Output format :
Print the total possible number of ways.
 Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1:
4
Sample Output 1:
7
Sample Input 2:
10
Sample Output 2:
274
*/

#include <iostream>
using namespace std;

long staircase(int n){
    long a[n+1];
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    for(int i = 4; i < n + 1; i++){
        a[i] = a[i-1] + a[i-2] + a[i-3];
    }
    return a[n];
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}