class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
       unordered_map<long, long> mp;
       long count= 0;
       long sum= 0;
       for (int i=0; i<arr.size(); i++){
           sum= sum^ arr[i];
           if(sum==k){
               count++;
           }
           count= count+ mp[sum^k];
           mp[sum]++;
       }
       return count;
       
    }
};
