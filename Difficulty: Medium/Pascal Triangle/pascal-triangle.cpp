class Solution {
    private:
    vector<int> generate_row(int row){
        long long ans=1;
        vector<int> temp;
        temp.push_back(ans);
        for(int col=1; col<row; col+=1){
            ans= ans* (row-col);
            ans= ans/(col);
            temp.push_back(ans);
            
        }
        return temp;
    }
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        // vector<vector<int>> ans;
        vector<int> temp;
        int ans=1;
        temp.push_back(ans);
        for(int i=1; i<n; i+=1){
            // ans.push_back(generate_row(i));
            ans= ans * (n-i);
            ans= ans/i;
            temp.push_back(ans);
            
        }
        return temp;
    }
};
