#include<iostream>
using namespace std;

void tower_of_hanoi(int n, char source, char auxilary, char destination){
    if(n==0){
        return;
    }

    if(n==1){
        cout<<source<<" "<<destination<<endl;
        return;
    }

    tower_of_hanoi(n - 1, source, destination, auxilary);
    cout<<source<<" "<<destination<<endl;
    tower_of_hanoi(n - 1, auxilary, source, destination);

}

int main(){
    int n;
    cin>>n;

    tower_of_hanoi(n, 'a', 'b', 'c');
}