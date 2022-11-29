/*Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
Input format :
String in a single line
Output format :
Word wise reversed string in a single line
Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
Sample Input 2:
Always indent your code
Sample Output 2:
code your indent Always*/
#include <iostream>
#include <cstring>
using namespace std;
void reverse(char input[],int x, int y){
    while(x<y){
        int temp=input[x];
        input[x]=input[y];
        input[y]=temp;
        x++;
        y--;
    }
}

void reverseStringWordWise(char input[]) {
    // Write your code here
    int length=0;
    for(int i=0;input[i]!='\0';i++){
        length++;
    }
    int len=length-1;;
    int i=0,j=len;
    while(i<j){
        int temp=input[i];
        input[i]=input[j];
        input[j]=temp;
        i++;
        j--;
    }
    int start=0,end=0;
    for(int i=0;i<=strlen(input);i++){
        if(input[i]==' ' || input[i]=='\0'){
            end=i-1;
            reverse(input,start,end);
            start=i+1;
        }
    }
    //end=i-1;
    //reverse(input,start,end);
}
int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
