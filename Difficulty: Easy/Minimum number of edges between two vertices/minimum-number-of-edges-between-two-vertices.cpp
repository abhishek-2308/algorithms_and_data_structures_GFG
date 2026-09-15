class Solution {
  public:
    int minEdges(int V, vector<vector<int>>& edges, int u, int v) {
        // code here
        vector<int> dist(V, INT_MAX);
        // vector<int> vis(V, 0);
        vector<vector<int>> adj(V);
        for(int i=0;  i<edges.size(); i+=1){
            int u= edges[i][0];
            int v= edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(u);
        dist[u]= 0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto i: adj[node]){
                if(dist[node]+1 < dist[i]){
                    q.push(i);
                    dist[i]= dist[node]+1;
                }
            }
        }
        return dist[v]== INT_MAX ? -1 : dist[v];
        
    }
};
