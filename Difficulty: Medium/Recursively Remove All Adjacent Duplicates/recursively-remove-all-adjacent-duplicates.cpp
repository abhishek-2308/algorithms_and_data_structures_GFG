class Solution {
    private:
    string remove_adjacent_duplicates(string &s){
        string ans="";
        int i=0;
        while(i<s.size()){
            int j= i+1;
            while(j<s.size() and s[i]==s[j]){
                j++;
            }
            if(j-i == 1){
                ans.push_back(s[i]);
            }
            i= j;
           
        }
        return ans;
    }
  public:
    string removeUtil(string &s) {
        // code here
        string ans= remove_adjacent_duplicates(s);
        if(s==ans){
            return ans;
        }
        return removeUtil(ans);
    }
};