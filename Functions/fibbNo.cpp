#include <iostream>
using namespace std;
bool checkMember(int n){

    int a,b,c;             //this prg is giving wrong output
    a=0,b=1;
    if(n==0 || n==1){
        return true;
    }
	
    for(int i=1;i<n;i++){
        c=a+b;
        if(c==n){
            return true;
        }
        a=b;
        b=c;
        
    }
	
    return false;
}

int main(){
    int n;
    cin>>n;
    
    bool ans=checkMember(n);
    cout<<ans;
    
}
