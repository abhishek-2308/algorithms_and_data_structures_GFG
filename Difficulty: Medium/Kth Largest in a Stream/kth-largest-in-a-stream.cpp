class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans;
        for(auto i: arr){
            pq.push(i);
            if(pq.size()>k){
                
                pq.pop();
            }
            if(pq.size()==k){
                ans.push_back(pq.top());
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};