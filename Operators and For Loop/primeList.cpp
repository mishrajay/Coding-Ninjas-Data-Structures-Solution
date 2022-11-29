#include <iostream>
using namespace std;

int main(){ 

    /* Read input as specified in the question.
	 * Print output as specified in the question.
	 */
    int n;
    cin>>n;
    int i,j,flag;
    
    for(i=2;i<=n;i++){
        flag=0; //every time when the second for loop will terminate this flag will be 
    //initialsed to 0 which would not have been done if flag=0; is given before first for loop
        for(j=2;j<=i/2;j++){
        	if(i%j==0){
            	flag++;
                //break;
        	}
        }
        if(flag==0){
        cout<<i<<endl;
    }
    
       
    }
     
}

