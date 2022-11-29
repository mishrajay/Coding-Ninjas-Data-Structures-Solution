#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

vector<char> removeDuplicates(char input[]){
    vector<char> v;
    unordered_map<char, bool> ourmap;
    for(int i = 0; input[i] != '\0'; i++){
        if(ourmap.count(input[i]) > 0){
            continue;
        }
        ourmap[input[i]] = true;
        v.push_back(input[i]);
    }
    return v;
}

int main(){
    int size;
    cin>>size;
    char str[size];
    cin>>str;
    vector<char> v = removeDuplicates(str);
    for(int i = 0; i < v.size(); i++){
        cout<<v[i];
    }
}