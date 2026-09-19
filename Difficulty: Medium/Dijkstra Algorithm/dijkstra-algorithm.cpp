class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(V);
        for(auto i: edges){
            int u= i[0];
            int v= i[1];
            int wt= i[2];
            adj[u].push_back(make_pair(v, wt));
            adj[v].push_back(make_pair(u, wt));
        }
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        vector<int> dist(V, 1e9);
        dist[src]=0;
        pq.push(make_pair(0, src));
        while(!pq.empty()){
            pair<int, int> top= pq.top();
            pq.pop();
            int node= top.second;
            int d= top.first;
            if(vis[node])continue;
            vis[node]=1;
            for(auto nbr : adj[node]){
                int weight= nbr.second;
                int v= nbr.first;
                if(!vis[v] and dist[node] + weight < dist[v]){
                    pq.push(make_pair(dist[node] + weight, v));
                    dist[v]= dist[node] + weight;
                }
            }
        }
        return dist;
    }
};