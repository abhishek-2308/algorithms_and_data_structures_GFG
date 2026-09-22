class Solution {
    private:
    void get_dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node]=1;
        for(auto i: adj[node]){
            if(!vis[i]){
                get_dfs(i, adj, vis);
            }
        }
    }
  public:
    bool isCircle(vector<string> &arr) {
        // code here
        vector<int> adj[26];
        vector<int> indeg(26, 0);
        vector<int> outdeg(26, 0);
        vector<int> vis(26, 0);
        for(int i=0; i<arr.size(); i+=1){
            string str= arr[i];
            int u= str[0]- 'a';
            int v= str[str.size()-1]-'a';
            adj[u].push_back(v);
            indeg[u]++;
            outdeg[v]++;
        }
        for(int i=0; i<26; i+=1){
            if(indeg[i] != outdeg[i])return 0;
        }
        int node= arr[0][0]-'a';
        get_dfs(node, adj, vis);
        for(int i=0; i<26; i+=1){
            if(indeg[i] and !vis[i])return false;
        }
        return 1;
    }
};