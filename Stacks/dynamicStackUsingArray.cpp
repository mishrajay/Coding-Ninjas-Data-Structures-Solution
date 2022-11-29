#include<climits> //for INT_MIN
class stackUsingArray{
    int *data;
    int nextIndex;
    int capacity;

    public :
    //default constructor
    stackUsingArray(){
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }

    //total no. of elements present in stack
    int size(){
        return nextIndex;
    }

    //stack is empty or not
    bool isEmpty(){
        return nextIndex == 0;
    }

    //insert elements in stack
    void push(int element){
        if(nextIndex == capacity){
            int *newData = new int[2 * capacity];
            for(int i = 0; i < capacity; i++){
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    //delete elements in stack
    int pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    //access the topmost element of stack
    int top(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
};