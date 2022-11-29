/*Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/
#include <iostream>
#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num==0 || num==1){
        output[0] = "";
        return 1;
    }
    int n = num % 10;
    num = num / 10;
    int smallOutputSize = keypad(num, output);
    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string smallAns = mapping[n];
    int totalOutputSize = smallOutputSize * smallAns.size();
    int k = 0;
    string temp[totalOutputSize];
    for(int i = 0; i < smallOutputSize; i++){
        for(int j = 0; j < smallAns.size(); j++){
            temp[k] = output[i] + smallAns[j];
            k++;
        }
    }
    for(int i = 0; i < totalOutputSize; i++){
        output[i] = temp[i];
    }
    return totalOutputSize;
}    

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << " ";
    }
    return 0;
}
