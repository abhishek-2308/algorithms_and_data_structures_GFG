class Solution {
    private:
    void get_ans(int n, vector<int> &ans){
        if(n<0){
          ans.push_back(n);
          return;
        } 
        if(n==0){
            ans.push_back(n);
            return;
        }
        ans.push_back(n);
        get_ans(n-5, ans);
        ans.push_back(n);
    }
  public:
    vector<int> pattern(int n) {
        // code here
        // if(n<0)return {n};
        vector<int> ans;
        get_ans(n, ans);
        return ans;
    }
};