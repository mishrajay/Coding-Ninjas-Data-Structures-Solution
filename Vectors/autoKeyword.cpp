#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    for(int i = 0 ; i < 10; i ++){
        v.push_back(i);
    }
    
    for(vector<int> :: iterator it = v.begin(); it != v.end(); it++){
        cout<<*it<<" ";
    }
    
    cout<<endl;
    
    for(auto it = v.begin(); it != v.end(); it++){
        cout<<*it<<" ";
    }
    
    cout<<endl;
    
    for(auto it : v){
        cout<<it<<" ";  //no * here like in the upper cases
    }
     
    cout<<endl;

    for(auto it : v){
        if(it < 5){
            cout<<it<<" ";
        }
    }
}