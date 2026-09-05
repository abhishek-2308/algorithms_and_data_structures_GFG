class Solution {
  public:
    int minSum(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int> , greater<int>> pq;
        for(auto i: arr){
            pq.push(i);
        }
        int ans= 0;
        while(!pq.empty() and pq.size()>1){
            int a= pq.top();
            pq.pop();
            int b= pq.top();
            pq.pop();
            ans+=a+b;
            pq.push(a+b);
        }
        return ans;
    }
};