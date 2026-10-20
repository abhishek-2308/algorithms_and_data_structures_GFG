class Solution {
    private:
    void get_ans(vector<int> &arr, vector<vector<int>> &ans, int index){
        
        if(index >= arr.size()){
            ans.push_back(arr);
            return;
        }
        for(int i= index; i< arr.size(); i+=1){
            swap(arr[i], arr[index]);
            get_ans(arr, ans, index+1);
            swap(arr[i], arr[index]);
        }
    }
  public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        vector<vector<int>> ans;
        int i=0;
        get_ans(arr, ans, i);
        return ans;
    }
};