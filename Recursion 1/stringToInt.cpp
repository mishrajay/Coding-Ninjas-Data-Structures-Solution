/*Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 <= |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567
*/

#include <iostream>
#include<cmath>
using namespace std;

int len(char input[]){
	int length = 0;
    for(int i = 0;input[i]!='\0';i++){
        length++;
    }
    return length;    
}   
//when we break string from beggining
/*
int stringToNumber(char input[]){
    int length = len(input);
    
    if(length==1){
        int b = (input[0] - '0' );
        return b;
    }
    
    int smallOutput = stringToNumber(input + 1);
    
    int length1 = len(input + 1);
    int a = input[0] - '0';
    int b = a * pow(10, length1);
    return b + smallOutput ;
}*/

//when we break the string from end
int stringToNumber(char input[], int lastIndex){
    if(lastIndex==0){
 		int b = (input[0] - 48);
        return b;
    }
    
    int smallOutput = stringToNumber(input, lastIndex - 1);

    int b = input[lastIndex] - 48;
    return smallOutput * 10 + b;
    
}
int stringToNumber(char input[]){
    int length = len(input);
    if(length==1){
 		int b = (input[0] - 48);
        return b;
    }
    
    int smallOutput = stringToNumber(input, length - 1);
    return smallOutput;
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
