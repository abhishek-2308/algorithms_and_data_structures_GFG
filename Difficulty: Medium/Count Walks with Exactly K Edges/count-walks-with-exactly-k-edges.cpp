class Solution {
    private:
    const int mod= 1e9 + 7;
    int get_ans(vector<vector<int>> &adj, int node, int &v, int k, vector<vector<int>> &dp){
        if(k==0)return node==v ? 1 : 0;
        if(dp[node][k] != -1)return dp[node][k];
        long long ans= 0;
        for(int i=0; i<adj.size(); i+=1){
            if(adj[node][i]==1){
                ans= (ans+ get_ans(adj, i, v, k-1, dp)) %mod;
            }
        }
        return dp[node][k]= ans % mod;
    }
  public:
    int minimumWalk(vector<vector<int>> &adj, int u, int v, int k) {
        
        vector<vector<int>> dp(adj.size(), vector<int> (k+1, -1));
        return get_ans(adj, u, v, k, dp) % mod;
        
    }
};