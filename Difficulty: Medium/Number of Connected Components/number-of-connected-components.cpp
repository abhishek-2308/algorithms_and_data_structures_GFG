class Solution {
    private:
    void get_dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node]=1;
        for(auto i: adj[node]){
            if(!vis[i]){
                get_dfs(i, adj, vis);
                
            }
        }
    }
  public:
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto i: edges){
            int u= i[0];
            int v= i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        vector<int> vis(V, 0);
        for(int i=0; i<V; i+=1){
            if(!vis[i]){
                count++;
                get_dfs( i, adj, vis);
            }
        }
        return count;
    }
};