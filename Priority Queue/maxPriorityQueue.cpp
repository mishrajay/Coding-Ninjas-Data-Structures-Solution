#include<vector>
#include<climits>
using namespace std;
class PriorityQueue {
    // Declare the data members here
    vector<int> pq;
    
   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0){
            int parentIndex = (childIndex - 1) / 2;
            if(pq[parentIndex] < pq[childIndex]){
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty()){
            return INT_MIN;
        }
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty()){
            return INT_MIN;
        }
        
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        
        int parentIndex = 0;
        int leftChildIndex = (2 * parentIndex) + 1;
        int rightChildIndex = (2 * parentIndex) + 2;
        
        while(leftChildIndex < pq.size()){
            int maxIndex = parentIndex;	//assume that the max element among parent, leftC and rightC is parent
            if(pq[leftChildIndex] > pq[maxIndex]){
                maxIndex = leftChildIndex;
            }
            
            if(pq[rightChildIndex] > pq[maxIndex] && rightChildIndex < pq.size()){
                maxIndex = rightChildIndex;
            }
            
            if(maxIndex == parentIndex){
                break;
            }
            
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            
            parentIndex = maxIndex;
            leftChildIndex = (2 * parentIndex) + 1;
        	rightChildIndex = (2 * parentIndex) + 2;
            
        }
        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size() == 0;
    }
};