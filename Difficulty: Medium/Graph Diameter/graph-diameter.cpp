class Solution {
    private:
    int get_dfs(vector<int> adj[], int node, vector<int> vis, int V, bool flag){
        queue<int> q;
        q.push(node);
        vis[node]=1;
        vector<int> dist(V, 1e9);
        dist[node]=0;
        while(!q.empty()){
           int front= q.front();
           q.pop();
           for(auto nbr : adj[front]){
               if(dist[front] + 1 < dist[nbr]){
                   q.push(nbr);
                   dist[nbr]= dist[front]+1;
               }
           }
        }
        int vertex= -1;
        int maxi= -1;
        for(int i=0; i<V; i+=1){
            if(dist[i]>maxi and dist[i] !=1e9){
                maxi= dist[i];
                vertex= i;
            }
            
        }
        // cout<<vertex;
        // return vertex;
        if(!flag)return vertex;
        if(flag)return maxi;
    }
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here()
        vector<int> adj[V];
        for(int i=0; i<edges.size(); i+=1){
            int u= edges[i][0];
            int v= edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(V, 0);
        int A= get_dfs(adj, 0, vis, V, 0);
        // return A;
        int B= get_dfs(adj, A, vis, V, 1);
        return B;
    }
};
