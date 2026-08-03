class Solution {
    private:
    void get_ans(vector<int> &arr, int sum, int index, vector<int> &ans){
        if(index>=arr.size()){
            ans.push_back(sum);
            return;
        }
        //include
        get_ans(arr, sum+arr[index], index+1, ans);
        
        //exclude
        get_ans(arr, sum, index+1, ans);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans;
        get_ans(arr, 0, 0, ans);
        return ans;
    }
};