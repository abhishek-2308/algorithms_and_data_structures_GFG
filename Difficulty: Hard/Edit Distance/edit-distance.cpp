class Solution {
    private:
    int min_operation(string &s1, string &s2, int n,  int m, vector<vector<int>> &dp){
      if(n<0)return m+1;
      if(m<0)return n+1;
      if(dp[n][m]!=-1)return dp[n][m];
        
        if(s1[n]==s2[m]){
            return 0 + min_operation(s1, s2, n-1, m-1, dp);
        }
        else{
            int insert=  1+ min_operation(s1, s2, n, m-1, dp);
            int dele= 1+ min_operation( s1, s2, n-1, m, dp);
            int replace= 1+ min_operation(s1, s2, n-1, m-1, dp);
            return dp[n][m]= min(insert, min(dele, replace));
        }
    }
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n= s1.size();
        int m= s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return min_operation(s1, s2, s1.size()-1, s2.size()-1, dp);
    }
};