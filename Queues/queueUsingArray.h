template<typename T>
class queueUsingArray{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public :
    queueUsingArray(){
        data = new T[4];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = 4;
    }

    T getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    //insert elements in queue
    void enqueue(T element){
        if(size == capacity){
            T *newData = new T[2 * capacity];
            int j = 0;
            for(int i = firstIndex; i < capacity; i++){
                newData[j++] = data[i];
            }
            for(int i = 0; i < firstIndex; i++){
                newData[j++] = data[i];
            }
            delete [] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            //cout<<"queue is full"<<endl;
            //return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        size++;
        if(firstIndex == -1){
            firstIndex = 0; //firstIndex points at the location at which the first element
        }                   //is inserted
    }

    //access the front element
    T front(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }

    //delete an element from queue
    T dequeue(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if(size == 0){
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};