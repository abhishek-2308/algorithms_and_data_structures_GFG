class Solution {
    private:
    
    priority_queue<int>  leftMaxHeap;
    priority_queue<int, vector<int>  , greater<int>> rightMinHeap;
  public:
  void balanceHeap(){
      if(leftMaxHeap.size()== rightMinHeap.size()){
          return;
      }
      else if(leftMaxHeap.size()-1 > rightMinHeap.size()){
          int top= leftMaxHeap.top();
          leftMaxHeap.pop();
          rightMinHeap.push(top);
      }
      else if(rightMinHeap.size()>leftMaxHeap.size()){
           int top= rightMinHeap.top();
          rightMinHeap.pop();
          leftMaxHeap.push(top);
      }
  }
  void push_ele(int ele){
      if(leftMaxHeap.empty()){
          leftMaxHeap.push(ele);
          return;
      }
      if(ele < leftMaxHeap.top()){
          leftMaxHeap.push(ele);
      }
      else{
          rightMinHeap.push(ele);
      }
      balanceHeap();
  }
    vector<double> getMedian(vector<int> &arr) {
        // code here
        vector<double> ans;
        for(int i=0; i<arr.size(); i+=1){
            push_ele(arr[i]);
            if(leftMaxHeap.size()> rightMinHeap.size()){
                double x= leftMaxHeap.top() / 1.0;
                ans.push_back(x);
            }
            else{
                double x= (leftMaxHeap.top() + rightMinHeap.top())/2.0;
                ans.push_back(x);
            }
        }
        return ans;
    }
};
