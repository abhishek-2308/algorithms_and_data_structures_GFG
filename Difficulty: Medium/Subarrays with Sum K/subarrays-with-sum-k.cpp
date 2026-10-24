class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> mp;
        int sum=0;
        mp[0]=1;
        int count=0;
        for(int i=0; i<arr.size(); i+=1){
            sum+= arr[i];
            if(mp.find(sum-k) != mp.end()){
                count+= mp[sum-k];
            }
            mp[sum]++;
            
        }
        return count;
    }
};