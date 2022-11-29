#include <iostream>
using namespace std;
#include<cmath> 

int subs(string input, string output[]){
    if(input.empty()){
        output[0] = "";
        return 1;
    }

    int smallStringSize = subs(input.substr(1), output);
    for(int i = 0; i < smallStringSize; i++){
        output[smallStringSize + i] = input[0] + output[i];
    }
    return 2 * smallStringSize;
}

int main(){
    string input;
    cin>>input;
    int t = input.size();
    int n = pow(2, t);
    string *output = new string[n];
    int x = subs(input, output);
    for(int i = 0; i < x; i++){
        cout<<output[i]<<" ";
    }
    delete [] output;
}