#include<cstring>
class student{
    private :
    int age;
    char *name;

    public:
    student(int age, char *name){
        this -> age = age;
        //this -> name = name;
        //this is shallow copy, so here only the address of first location
        //of array is copied and the changes in the main's copy will also be reflected here as
        //both are pointing towards the same address.
        //to avoid this problem, we'll copy the entire array here, so the changes done in 
        //main's copy will not be done here.

        //deep copy
        this -> name = new char[strlen(name) + 1];//+ 1 is done to copy the null char also
        strcpy(this -> name, name);

        //constuctor is called only once for an object at the time of its creation,
        //so when s1.display() is called after name[0] = 'x', it will still have the same 
        //name as it was having before name [0] = 'x';
        }

    void display(){
        cout<<name<<" "<<age<<endl;
    }
};