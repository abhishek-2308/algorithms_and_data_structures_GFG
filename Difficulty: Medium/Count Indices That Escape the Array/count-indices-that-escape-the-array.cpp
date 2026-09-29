class Solution {
    
    private:
    int count;
    bool get_dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &path){
        vis[node]= path[node]=1;
        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                if(get_dfs(nbr, vis, adj, path))return 1;
            }
            else if(path[nbr])return 1;
        }
        count+=1;
        return path[node]=0;
    }
  public:
    int goodIndicies(vector<int> &arr) {
        // code here
        count=0;
        vector<int> adj[arr.size()];
        vector<int> vis(arr.size());
        vector<int> path(arr.size());
        for(int i=0; i<arr.size(); i+=1){
            int node= i + arr[i];
            if(node >=0 and node < arr.size()){
                adj[i].push_back(node);
            }
        }
        for(int i=0; i<arr.size(); i+=1){
            if(!vis[i]){
                get_dfs(i, vis, adj, path);
            }
        }
        return count;
    }
};