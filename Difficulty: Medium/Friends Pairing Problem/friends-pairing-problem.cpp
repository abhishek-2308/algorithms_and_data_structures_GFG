class Solution {
    private:
    int count_freinds_pair(int n, vector<int> &dp){
        if(n<=1)return 1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]= count_freinds_pair(n-1, dp) + (n-1)* count_freinds_pair(n-2, dp);
    }
  public:
    int countFriendsPairings(int n) {
        // code here
        vector<int> dp(n+1, 0);
        // return count_freinds_pair(n, dp);
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=n; i++){
            dp[i]= dp[i-1] + (i-1) * dp[i-2];
        }
        return dp[n];
    }
};
