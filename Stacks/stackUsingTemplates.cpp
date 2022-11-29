 template<typename T>
 class stackUsingTemplates{
    T *data;
    int nextIndex;
    int capacity;

    public :
    //default constructor
    stackUsingTemplates(){
        data = new T[4];
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
    void push(T element){
        if(nextIndex == capacity){
            T *newData = new T[2 * capacity];
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
    T pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;   //0 can be used in any data type
        }
        nextIndex--;
        return data[nextIndex];
    }

    //access the topmost element of stack
    T top(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        return data[nextIndex-1];
    }
};