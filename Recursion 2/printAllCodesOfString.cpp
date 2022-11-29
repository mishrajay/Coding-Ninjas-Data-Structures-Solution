/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
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

void printAllPossibleCodes(string input, string output){
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    int x = input[0] - '0';
    char y = 'a' + x - 1;
    printAllPossibleCodes(input.substr(1), output + y);
    int p = (input[0] - '0') * 10 + (input[1] - '0');
    if(p <= 26 && p >= 11){
        char q = 'a' + p - 1;
        printAllPossibleCodes(input.substr(2), output + q);
    }
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    printAllPossibleCodes(input, "");
}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
