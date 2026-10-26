class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int n= arr.size();
        int start= arr[0][0];
        int end= arr[0][1];
        for(int i=1; i<n; i+=1){
            if(arr[i][0]<=end){
                end= max(end, arr[i][1]);
                
            }
            else{
                ans.push_back({start, end});
                start= arr[i][0];
                end= arr[i][1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};