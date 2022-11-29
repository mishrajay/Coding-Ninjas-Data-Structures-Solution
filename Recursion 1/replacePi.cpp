/*Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
*/
#include <iostream>
using namespace std;

int len(char input[]){
    int length = 0;
    for(int i=0; input[i]!='\0'; i++){
        length++;
    }
    return length;
}
void replacePi(char input[]) {
	// Write your code here
	
    int length = len(input);//here, length variable represents the length of inputted string
    if(length==0 || length==1){
        return;
    }
    
    replacePi(input + 1);
    
    if(input[0]=='p' && input[1]=='i'){
        length = len(input);//here, length variable represents the length of string whose first
        for(int i = length - 1; i>=2; i--){//char is remaining to be dealt in small calc part
            input[i + 2] = input[i];//and rest of the string have been dealt in recursive call
        }//so, the length of both avobe mentioned length variables is different.
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';

        length = len(input);//here, length variable represents the length of resultant string
        input[length] = '\0';
    }
    
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
