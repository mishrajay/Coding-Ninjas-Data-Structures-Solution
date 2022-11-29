// Arrays in Classes
// Arrays are used to store multiple values of the same type. An array is very helpful 
// when multiple variables are required, instead of making multiple variables one array 
// can be used which can store multiple values. 
#include <iostream>
using namespace std;

class shop{
    int itemId[100];
    int itemPrice[100];
    int counter; 

    public : 
    void init_counter(void) { counter =0; }//this function is only created to make 
    //the value of all objects as 0 initially and in this prg we have made only one object 
    //ie, dukaan 
    void setPrice(void);
    void displayPrice (void);

};

void shop :: setPrice(void){
    cout<<"enter id of the item no. "<<counter+1<<endl;
    cin>>itemId[counter];//this will show the itemId of index(counter) 1 
    cout<<"enter price of the item no. "<<counter+1<<endl;
    cin>>itemPrice[counter];
    counter++;         //and then the index(counter) will keep on increasing its value by 1
//instead of using counter++ we can also use a counter increament functio like we used 
//void init_counter(void) for making the value of all onjects intially as 1
}

void shop :: displayPrice(void){
    for ( int i = 0; i < counter; i++)
    {
        cout<<"the price of item with item id "<<itemId[i]<<" is "<<itemPrice[i]<<endl;
    }
    
}

int main(){
    shop dukaan;//here dukaan is an object of class "shop"
    dukaan.init_counter();
    int n;
    cout<<"enter the no. of items=";
    cin>>n;
    for (int j = 0; j < n; j++)
    {
        dukaan.setPrice();
    }
    
    dukaan.displayPrice();
    return 0;
}