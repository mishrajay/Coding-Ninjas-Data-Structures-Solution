#include <iostream>
using namespace std;

//calculation of volume  of cuboid
int volume(int a, int b, int c){
    return (a*b*c);
}

//calculation of volume of cube
int volume(int a){
    return (a*a*a);
}

//calculation of volume of cylinder
int volume(int a, int b){
    return (3.14*a*a*b);
}

int main(){
    cout<<"the volume of cuboid of dimensions 5,6,7 is "<<volume(5,6,7)<<endl;
    cout<<"the volume of cube of dimensions 5 is "<<volume(5)<<endl;
    cout<<"the volume of cylinder of dimensions 5,6 is "<<volume(5,6)<<endl;
    //we can use different functions of same function name in same prg and the function 
    //call gives the output accordingly ie, based on the number of arguments.
    return 0;
}
