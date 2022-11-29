class fraction{
    private :
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

    void simplify(){//here, there are no arguments so num will automatically mean this -> num
        int gcd = 0;//so, we can write num or this -> num, no boundations.
        int j = min(num, den);
        for(int i = 1; i <= j; i++){
            if(num % i ==0 && den % i ==0){
                gcd = i;
            }
        }

        num = num / gcd;
        den = den / gcd;
    }

    void add(fraction const &f2){//const is used so that we do not change the values of f2's
        int lcm = den * (f2.den);//num and den, as changing them here will lead to change them
        int x = (lcm / den) * num;//in main too as we haven't created the copy of f2, we passed 
        int y = (lcm / f2.den) * (f2.num);//it by reference.
        num = (x + y);
        den = lcm;
        simplify();//we haven't used any arguments as simplify() implicitly means 
                   //this -> simplify, so the values in this will be called in simplify fn 
    }

};