// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
    private:
    void heapify(int index, vector<int> &arr, int n){
        int largest= index;
        int left= 2*index+1;
        int right= 2*index+2;
        if(left < n and arr[left]>arr[largest]){
            largest= left;
        }
        if(right < n and arr[right] > arr[largest]){
            largest= right;
        }
        if(largest !=  index){
            swap(arr[largest], arr[index]);
            heapify(largest, arr, n);
        }
        else return;
    }
    void heap_sort(vector<int> &arr){
        int size= arr.size();
        // int x= arr.size
        for(int i= size-1; i>=0; i--){
            swap(arr[0], arr[i]);
            heapify(0, arr, i);
        }
    }
  public:
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
        int  n= arr.size();
        for (int i=(arr.size()/2)-1; i>=0; i--){
            heapify(i, arr, arr.size());
        }
        heap_sort(arr);
    }
};