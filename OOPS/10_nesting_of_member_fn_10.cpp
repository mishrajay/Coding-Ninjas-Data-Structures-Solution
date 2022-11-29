// Nesting of Member Functions
// If one member function is called inside the other member function of the same class 
// it is called nesting of a member function.
#include <iostream>
#include <string>
using namespace std;
//if any member function is not mentioned as public or private 
    //then by default it will be treated as private member function
class binary{
    
    private :
    string s;
    void check_bin(void);//now check_bin() can only be accessed by the member functions 
                         //of class 

    public :
    void read(void);
    //void check_bin(void);
    void one_s_complement(void);
    void display(void);
};

void binary :: read(void){
    cout<<"enter a binary number= ";
    cin>>s;
}

void binary :: check_bin(void){
    for (int i=0; i < s.length(); i++)
    {
        if(s.at(i)!='0' && s.at(i)!='1')
        {
            cout<<"the number is not binary";
            exit(0);
        }
    }
    
}

void binary :: one_s_complement(void){
    
    for ( int i = 0; i < s.length(); i++)
    {
        if (s.at(i)=='0')
        {
            s.at(i)='1';
        }

        else{
            s.at(i)='0';
        }
    }
    
}

void binary :: display(void){
    check_bin();                        //this is nesting of member functions
    //as check_bin() has been made private function it can be accessed by display()
    //as display() is a member function of class but cannot be accessed by int main()
    cout<<"this is your binary number= ";
    for (int i = 0; i < s.length(); i++)
    {
        cout<<s.at(i);
    }
    cout<<endl;
}

//driver program
int main(){
    binary b;
    b.read();
    //b.check_bin();
    b.display();
    b.one_s_complement();
    b.display();
    return 0;
}

//you can check the descrription of the videos of code with harry for complete and clear notes