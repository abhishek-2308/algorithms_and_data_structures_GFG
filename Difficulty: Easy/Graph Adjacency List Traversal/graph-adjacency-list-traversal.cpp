class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto i: edges){
            int u= i.first;
            int v= i.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
};