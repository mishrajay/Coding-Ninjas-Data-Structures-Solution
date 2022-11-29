/*Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false
*/
#include <iostream>
using namespace std;

bool checkPal(char input[], int si, int ei){
    while(si<ei){
        if(input[si]!=input[ei]){
            return false;
        }
    
    bool ans = checkPal(input, si + 1, ei - 1);
    return ans;
    }
}

bool checkPalindrome(char input[]) {
    // Write your code here
    int length = 0;
    for(int i=0;input[i]!='\0';i++){
        length++;
    }
    
	if(length==0 || length==1){
        return true;
    }
    
    int len = length - 1;
    int start = 0, end = len;
    
    if(input[start]!=input[end]){
        return false;
    }
    
    bool smallOutput = checkPal(input, start + 1 , end - 1);
    return smallOutput;
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
