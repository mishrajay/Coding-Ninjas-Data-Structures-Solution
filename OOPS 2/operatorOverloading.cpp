#include<iostream>
using namespace std;
#include<algorithm>
class fraction {
    int num;
    int den;

    public :
    fraction(int num, int den){
        this -> num = num;
        this -> den = den;
    }

    void print(){
        cout<<num<<" / "<<den<<endl;
    }

    void simplify(){
        int gcd = 0;
        int j = min(num, den);
        for(int i = 1; i <= j; i++){
            if(num % i ==0 && den % i ==0){
                gcd = i;
            }
        }

        num = num / gcd;
        den = den / gcd;
    }

    fraction add(fraction const &f2) const { 
        int lcm = den * (f2.den);
        int x = (lcm / den) * num;
        int y = (lcm / f2.den) * (f2.num);
        int n = x + y;
        fraction fNew(n, lcm);
        fNew.simplify(); 
        return fNew;
    }

    fraction operator+ (fraction const &f2) const { 
        int lcm = den * (f2.den);
        int x = (lcm / den) * num;
        int y = (lcm / f2.den) * (f2.num);
        int n = x + y;
        fraction fNew(n, lcm);
        fNew.simplify(); 
        return fNew;
    }

    fraction operator* (fraction const &f2) const {
        int x = num * f2.num;
        int y = den * f2.den;
        fraction fNew(x, y);
        fNew.simplify();
        return fNew;
    }

    bool operator== (fraction const &f2) const {
        return (num == f2.num && den == f2.den);
    }
};