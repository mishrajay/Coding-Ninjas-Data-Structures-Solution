#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n,n1;
    cin>>n;
    int prev,curr;
    for(int i=1;i<=n;i++){
        cin>>n1;
        if(i==1){
            prev=n1;
        }
        else if(i==2){
            curr=n1;
        }
    }
    
    bool isDec=true;
    int j=1;
    while(j<n){
        if(prev==curr){
            cout<<"false";
            break;
            
        }
        
        else if(curr<prev){
            isDec=true;
            cout<<"true";
            break;
        }
        else if(curr>prev){
            cout<<"true";
            break;
        	}
        else if(curr<prev){
            if(isDec==false){
                cout<<"true";
            	}
            else{
                cout<<"false";
            	}
        }
        prev=curr;
        j++;
    	}
    
}
