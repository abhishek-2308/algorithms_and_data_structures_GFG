class minHeap {
  private:
    // Initialize your data members
vector<int> pq;
  public:
void heapify_UP(int size){
    int index= size;
    while(index>0){
        int  parent= (index-1)/2;
        if(pq[parent]>pq[index]){
            swap(pq[parent], pq[index]);
            index= parent;
        }
        else{
            return;
        }
    }
}
void heapify_Down(int size){
    int index=0;
    while(index<size){
        int  smallest= index;
        int  left= 2*index+1;
        int right= 2*index+2;
        if(left<size and pq[left]<pq[smallest]){
            smallest= left;
        }
        if(right<size and pq[right]< pq[smallest]){
            smallest= right;
        }
        if(smallest != index){
            swap(pq[smallest], pq[index]);
            index= smallest;
        }
        else{
            return;
        }
    }
}
    void push(int x) {
        // Insert x into the heap
        pq.push_back(x);
        heapify_UP(pq.size()-1);
    }

    void pop() {
        // Remove the top (minimum) element
        if(pq.size()==0)return ;
        int ele= pq[0];
        swap(pq[0], pq[pq.size()-1]);
           pq.pop_back();
        heapify_Down(pq.size());
    }

    int peek() {
        // Return the top element or -1 if empty
        if(pq.empty())return -1;
        return pq[0];
    }

    int size() {
        // Return the number of elements in the heap
    return pq.size();
    }
};