class student{
    public :
    int age;
    int const rollNo;
    int &x;        //reference variable for age

    student(int rollNo, int a) : rollNo(rollNo) , age(a), x(this -> age){
        //we can use rollNo also instead of r and that too w/o 'this', coz it's very clear 
        //that one rollNo is an argument and one is data member
    }

    void display(){
        cout<<rollNo<<" "<<age<<" "<<x;
    }
};