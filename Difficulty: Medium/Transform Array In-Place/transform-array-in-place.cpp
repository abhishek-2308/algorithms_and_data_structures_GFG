class Solution {
  public:
    void arrange(vector<int>& arr) {
        //  code here
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i+=1)
        mp.insert({i, arr[i]});
        for(auto i: mp){
            arr[i.first]= mp[i.second];
        }
        
    }
};