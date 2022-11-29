class dynamicArray {
    int *data;
    int nextIndex;
    int capacity;

    public :
    //default constructor
    dynamicArray(){
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    //for copy cosntructor
    dynamicArray(dynamicArray const &d){
        //this -> data = d.data;        shallow copy
        this -> data = new int[d.capacity];
        for(int i = 0; i < d.nextIndex; i++){
            this -> data[i] = d.data[i];
        }
        this -> nextIndex = d.nextIndex;
        this -> capacity = d.capacity;
    }

    //copy-assignment operator
    void operator= (dynamicArray const &d){
        //this -> data = d.data;        shallow copy
        this -> data = new int[d.capacity];
        for(int i = 0; i < d.nextIndex; i++){
            this -> data[i] = d.data[i];
        }
        this -> nextIndex = d.nextIndex;
        this -> capacity = d.capacity;
    }

    void add(int element){
        if(nextIndex == capacity){
            int *newData = new int[2 * capacity];
            for(int i = 0; i < nextIndex; i++){
                newData[i] = data[i];//the scope of newData is within 'if' only
            }
            delete [] data;//so we need to de-allocate data and assign the address of newData
            data = newData;//to data, as data has global scpoe
        }
        data[nextIndex++] = element;
        capacity *= 2;
    }

    void add(int i, int element){
        if(i < nextIndex){
            data[i] = element;
        }
        else if(i == nextIndex){
            add(element);
        }
        else{
            return;
        }
    }

    int get(int i) const {
        if(i < nextIndex){
            return data[i];
        }
        else{
            return -1;
        }
    }

    void print() const {
        for(int i = 0; i < nextIndex; i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

};