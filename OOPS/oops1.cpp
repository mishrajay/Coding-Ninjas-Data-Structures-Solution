#include<iostream>
using namespace std;
//private members can be accessed only within the class or by the member fn of the same class.
class student{
    public :
    int rollNo;//here, rollNo is called data member.

    private :
    int age;

    public :
    void display(){
        cout << age << endl;
    }

    int getAge(){
        return age;
    }

    //you might get a thought that if we can access the private members using other public
    //members then what's the use of private fn, we could've made that fn public instead.
    //but, it's not like that, like the setAge fn here, we can set a check like password,
    //negative age, etc. so that it can be accessed only by some authorised people.
    void setAge(int a, int password){
        if(password != 123){
            return;
        }
        if(age < 0){
            return;
        }
        age = a;
    }
};
