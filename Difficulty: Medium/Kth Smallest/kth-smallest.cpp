class Solution {
    private:
    int index=-1;
    void push_(vector<int> &pq, int ele){
        index++;
        int size= index;
        pq[size]= ele;
        while(size>0){
            int parent= (size-1)/2;
            if(pq[parent]<pq[size]){
                swap(pq[parent], pq[size]);
                size= parent;
                
            }
            else{
                return;
            }
            
        }
    }
    void heapify_down( vector<int> &pq, int index){
        int largest= index;
        int left= 2*index+1;
        int right= 2*index+2;
        if(left < pq.size() and pq[largest]< pq[left]){
            largest= left;
        }
        if(right < pq.size() and pq[largest] < pq[right]){
            largest= right;
        }
        if(largest != index){
            swap(pq[largest], pq[index]);
            heapify_down(pq, largest);
        }
        else{
            return;
        }
        
    }
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        vector<int> pq(arr.size());
        for(int  i=0; i<k ;i++){
            push_(pq, arr[i]);
        }
        
        for(int i= k; i<arr.size(); i+=1){
            if(arr[i]< pq[0]){
                pq[0]= arr[i];
                heapify_down(pq, 0);
            }
        }
        return pq[0];
    }
};