#include<iostream>
using namespace std;

int main(){

    /* Read input as specified in the question.
	 * Print output as specified in the question.
	 */
    char c;
    int character=0,digit=0,space=0;
    while(c!='$'){
        c=cin.get();
        if(c>='a' && c<='z' || c>='A' && c<='Z'){
            character++;
        }
        else if(c>='0' && c<='9'){
            digit++;
        }
        else if(c==' ' || c=='\n' || c=='\t'){
            space++;
        }

    }
    cout<<character<<" ";
   
    cout<<digit<<" ";
    
    cout<<space;
}