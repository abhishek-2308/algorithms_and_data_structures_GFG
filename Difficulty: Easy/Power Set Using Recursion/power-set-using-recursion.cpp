class Solution {
    private:
    void get_ans(string &s, string temp, int index, vector<string> &ans){
        if(index>=s.size()){
            ans.push_back(temp);
            return;
        }
        //princiole of inclusion and declusing
        //take not take
        temp.push_back(s[index]);
        get_ans(s, temp, index+1, ans);
        //not take backtracking
        temp.pop_back();
        get_ans(s, temp, index+1,ans);
        
    }
  public:
    vector<string> powerSet(string s) {
        // code here
        vector<string> ans;
        get_ans(s, "", 0, ans);
        return ans;
    }
};
