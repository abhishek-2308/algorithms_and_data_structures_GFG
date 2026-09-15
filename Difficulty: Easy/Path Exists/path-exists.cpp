class Solution {
  public:
    bool checkPath(int V, vector<vector<int>>& edges, int src, int dest) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto i: edges){
            int u= i[0];
            int v= i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(V, 0);
        queue<int> q;
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto i: adj[node]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        if(!vis[dest])return false;
        return 1;
    }
};
