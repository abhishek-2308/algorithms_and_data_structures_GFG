class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto i: edges){
            int u= i[0];
            int v= i[1];
            int wt= i[2];
            adj[u].push_back(make_pair(v, wt));
            adj[v].push_back(make_pair(u, wt));
        }
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq;
        pq.push(make_pair(0, 0));
        int total=0;
        vector<int> vis(V, 0);
        while(!pq.empty()){
            pair<int, int> top= pq.top();
            pq.pop();
            int wt= top.first;
            int node= top.second;
            if(vis[node]){
                continue;
            }
            vis[node]=1;
            total+=wt;
            for(int j=0; j<adj[node].size(); j+=1){
                if(!vis[adj[node][j].first]){
                    pq.push(make_pair(adj[node][j].second,adj[node][j].first));
                }
            }
        }
        return total;
    }
};