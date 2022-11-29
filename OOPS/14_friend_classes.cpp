#include <iostream>
using namespace std; 

class complex; //forward declaration
               //compiler will read the prg from beginning and when it will read the 
               //calculator class, it will also read the arguments(objects of complex class).
               //So we need to assure the compiler that there is a class named complex which 
               //is defined below calculator and to assure the compiler we will write the 
               //forward declaration
class calculator{
    public:
    int sumRealNumber(complex, complex);//here only the function is declared and
                                        // o1,o2 are also not written coz 
    int sumCompNumber(complex, complex);

};

class complex{
    int a,b;
    friend int calculator :: sumRealNumber(complex, complex);
    friend int calculator :: sumCompNumber(complex, complex);
    //to make all the functions a friend 
    //friend class calculator;
    public :
    void setNumber(int x, int y){
        a=x;
        b=y;
    }

    void printNumber(){
        cout<<"your complex number is "<<a<<"+ i"<<b<<endl;
    }
};

int calculator :: sumRealNumber(complex o1, complex o2)
    {
        return (o1.a+ o2.a);
    }
int calculator :: sumCompNumber(complex o1, complex o2){
        return (o1.b + o2.b);
    }

int main(){
    complex o1,o2;
    o1.setNumber(1,2);
    o2.setNumber(3,4);

    calculator calc;
    int res= calc.sumRealNumber(o1,o2);
    cout<<"the sum of real part of the complex number= "<<res<<endl;
    int resc= calc.sumCompNumber(o1,o2);
    cout<<"the sum of complex part of the complex number= "<<resc<<endl;

    return 0;
}
