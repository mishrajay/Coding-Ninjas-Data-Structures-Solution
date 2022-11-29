#include<iostream>
using namespace std;

int len(char arr[]){
    if(arr[0]=='\0'){
        return 0;
    }

    return len(arr + 1) + 1;
}

void removeX(char arr[]){
    int length = len(arr);
    if(length==0){
        return;
    }

    if(arr[0]=='x'){
        for(int i = 0; arr[i]!='\0';i++){
            arr[i] = arr[i + 1];
        }
        removeX(arr);
    }
    else{
        removeX(arr + 1);
    }
}

int main(){
    int size;
    cin>>size;

    char *arr = new char[size];
    cin>>arr;
    removeX(arr);
    cout<<arr;

}