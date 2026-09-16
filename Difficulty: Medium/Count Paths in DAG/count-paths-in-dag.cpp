class Solution {
    private:
    int get_ans(int node, int &dest, vector<vector<int>> &adj, vector<int> &dp){
        if(node==dest){
            return 1;
            // return;
        }
      if(dp[node] != -1)return dp[node];
      int count=0;
        for(auto nbr: adj[node]){
           count+= get_ans(nbr, dest, adj, dp);
        }
        // vis[node]=0;
        return dp[node]= count;
    }
  public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto i: edges){
            int u= i[0];
            int v= i[1];
            adj[u].push_back(v);
            
        }
        vector<int> dp(V, -1);
        // int count=0;
       return get_ans(src, dest, adj, dp);
        // return count;
        
    }
};