class Solution {
  public:
    int maxDistinctNum(vector<int>& arr, int k) {
        // code here
         unordered_map<int, int> mp;
         for(int i=0; i<arr.size(); i+=1){
             mp[arr[i]]++;
         }
         priority_queue<int> pq;
         for(auto i: mp){
             pq.push(i.second);
         }
         while(!pq.empty() and k--){
             int top= pq.top();
             pq.pop();
             top--;
             if(top>0){
                 pq.push(top);
             }
         }
         return (int)pq.size();
    }
};