class Solution {
    private:
    void get_ans(int node,vector<int> &vis,vector<int> adj[],vector<vector<int>> &ans, int par, vector<int> &low, vector<int> &disc, int &count){
        disc[node]= count;
        low[node]= count;
        count++;
        vis[node]=1;
        for(auto nbr : adj[node]){
            if(nbr== par){
                continue;
            }
            else if(vis[nbr] and nbr != par){
                low[node]= min(low[node], low[nbr]);
            }
            else {
                get_ans(nbr,vis,adj, ans, node, low, disc, count);
                low[node]= min(low[node], low[nbr]);
                if(disc[node] < low[nbr]){
                    vector<int> temp;
                    temp.push_back(node);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }
            }
        }
    }
  public:
    vector<vector<int>> criticalConnections(int v, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> ans;
        vector<int> vis(v, 0);
        vector<int> adj[v];
        for(int i=0; i<edges.size(); i+=1){
            int u= edges[i][0];
            int v= edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> low(v, 0);
        vector<int> disc(v, 0);
        int count=0;
        get_ans(0, vis, adj, ans, -1, low, disc, count);
        return ans;
    }
};