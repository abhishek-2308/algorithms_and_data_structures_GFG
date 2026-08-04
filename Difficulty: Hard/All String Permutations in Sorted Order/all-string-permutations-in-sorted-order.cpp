class Solution {
    private:
    void get_ans(string &s, vector<string> &ans, int index){
        if(index>=s.size()){
            ans.push_back(s);
            return;
        }
        for(int i= index; i<s.size(); i++){
            swap(s[i], s[index]);
            get_ans(s, ans, index+1);
            swap(s[i], s[index]);
        }
    }
  public:
    vector<string> permutation(string s) {
        // code here
        vector<string> ans;
        get_ans(s, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};