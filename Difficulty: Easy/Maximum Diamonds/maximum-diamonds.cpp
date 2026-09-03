class Solution {
  public:
    long long maxDiamonds(vector<int>& arr, int k) {
        // code here
        priority_queue<long long> pq;
        for(int i=0; i<arr.size(); i++){
            pq.push(arr[i]);
        }
        long long ans= 0;
        while(k--){
            long long top= pq.top();
            pq.pop();
            
            ans+=top;
            
            long long temp= top/2;
           
            pq.push(temp);
        }
        return ans;
    }
};