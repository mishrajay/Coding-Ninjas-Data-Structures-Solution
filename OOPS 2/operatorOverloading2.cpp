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

    //pre-increment operator
    fraction& operator++(){//if we don't write & in return type, a copy of *this would be  
        num = num + den;//created in buffer, and the nested ++ operation would've been
        simplify();//done on that copy and f2 = 7/1 but f1 = 6/1. But we need both f1 and
        return *this;//f2 as 7/1, so we wrote & in return type, so that no copy is created
    }               //in buffer, and & will point to itself.


};