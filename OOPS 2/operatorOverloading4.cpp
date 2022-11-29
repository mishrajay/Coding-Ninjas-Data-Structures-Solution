class fraction {
    int num;
    int den;

    public :

    fraction(int num , int den){
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
            if(num % i ==0 && den % i == 0){
                gcd = i;
            }
        }

        num = num / gcd;
        den = den / gcd;
    }

    //post-increment operator
    fraction operator++ (int){//to differentiate b/w pre and post-increment, we generally 
        fraction fNew(num, den);//write int keyword in the argument.
        num = num + den;
        simplify();
        fNew.simplify();
        return fNew;
    }

    fraction& operator+= (fraction const &f2){
        int lcm = den * (f2.den);
        int x = (lcm / den) * num;
        int y = (lcm / f2.den) * (f2.num);
        int n = x + y;
        num = n;
        den = lcm;
        simplify();
        return *this;
    }


};