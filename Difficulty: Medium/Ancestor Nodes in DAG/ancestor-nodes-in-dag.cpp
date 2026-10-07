class Solution {
    private:
    void get_topo(int node, vector<int> &vis, vector<int> adj[], stack<int> &topo){
        vis[node]=1;
        for(auto i: adj[node]){
            if(!vis[i]){
                get_topo(i, vis, adj, topo);
            }
        }
        topo.push(node);
    }
    void get_bfs(int rnode, vector<int> adj[], vector<vector<int>> &ans, vector<int> &vis, int node){
       vis[node]=1;
       for(auto i: adj[node]){
           if(!vis[i]){
               ans[i].push_back(rnode);
               get_bfs(rnode, adj, ans, vis, i);
           }
       }
    }
  public:
    vector<vector<int>> findAnc(int V, vector<vector<int>> &edges) {
        // Code here
        //findn the topo;
        stack<int> topo;
        vector<int> vis(V, 0);
        vector<int> adj[V];
        for(auto i: edges){
            int u= i[0];
            int v= i[1];
            adj[u].push_back(v);
        }
        for(int i=0; i< V; i+=1){
            if(!vis[i]){
                get_topo(i, vis, adj, topo);
            }
        }
        vis.assign(V, 0);
        vector<vector<int>> ans(V);
        while(!topo.empty()){
            int rnode= topo.top();
            topo.pop();
            vector<int> _vis(V, 0);
            get_bfs(rnode, adj, ans, _vis, rnode);
        }
        for(auto &i : ans){
            sort(i.begin(), i.end());
        }
        return ans;
        
    }
};
