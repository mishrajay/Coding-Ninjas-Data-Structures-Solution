/*Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S
Output format :
Modified string
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a
*/
#include <iostream>
using namespace std;

// Change in the given string itself. So no need to return or print the changed string.
int len(char input[]){
	int length = 0;
    for(int i = 0;input[i]!='\0';i++){
        length++;
    }
    return length;    
}   

void pairStar(char input[]) {
    // Write your code here
    int length = len(input);
	if(length==1){
        return;
    }
    
    pairStar(input + 1);
    if(input[0]==input[1]){
        int length = len(input);
        for(int i = length - 1; i>=1; i--){
            input[i + 1] = input[i];
        }
        input[1] = '*';
        input[length + 1] = '\0';
    }
}


int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
