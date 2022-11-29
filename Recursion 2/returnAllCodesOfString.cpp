/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/

#include <iostream>
#include <string.h>
using namespace std;

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Donât print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    
    string result1[10000], result2[10000];
    int smallOutput1 = getCodes(input.substr(1), result1);
    int x = input[0] - '0';
    int k = 0;
    for(int i = 0; i < smallOutput1; i++){
        char y = 'a' + x - 1;
        output[k++] = y + result1[i];
    }
    if(input.size() > 1){
    int p = (input[0] - '0') * 10 + (input[1] - '0');
    
    if(p <= 26 && p >= 10){
        int smallOutput2 = getCodes(input.substr(2), result2);
    	for(int i = 0; i < smallOutput2; i++){
        	char q = 'a' + p - 1;
        	output[k++] = q + result2[i];
    	}
    }
    }    
    return k;
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}