class Solution {
  public:
    vector<vector<int>> getSubArrays(vector<int>& arr) {
        // code here
        vector<vector<int>>ans;
        for(int i=0; i<arr.size(); i++){
            vector<int> temp;
            for(int j=i; j<arr.size(); j++){
                temp.push_back(arr[j]);
                ans.push_back(temp);
            }
            
        }
        return ans;
    }
};