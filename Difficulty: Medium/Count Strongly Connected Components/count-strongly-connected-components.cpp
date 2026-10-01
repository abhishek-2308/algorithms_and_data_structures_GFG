class Solution {
    private:
    void get_dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
        vis[node]=1;
        for(auto i: adj[node]){
            if(!vis[i]){
                get_dfs(i, adj, vis, st);
            }
        }
        st.push(node);
    }
    void get_ans(int node, vector<int> adj[], vector<int> &vis){
        vis[node]=1;
        for(auto i: adj[node]){
            if(!vis[i]){
                // get_dfs(i, adj, vis, st);
                get_ans(i, adj, vis);
            }
        }
    }
  public:
    int countSCC(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> adj1[V];
        vector<int> adj2[V];
        for(int i=0; i<edges.size(); i+=1){
            int u= edges[i][0];
            int v= edges[i][1];
            adj1[u].push_back(v);
            adj2[v].push_back(u);
        }
        stack<int> st;
        vector<int> vis1(V);
        for(int i=0; i<V; i+=1){
            if(!vis1[i]){
                get_dfs(i, adj2, vis1, st);
            }
        }
        int count=0;
        vector<int>vis2(V);
        while(!st.empty()){
            int node= st.top();
            st.pop();
            if(!vis2[node]){
                count+=1;
                get_ans(node, adj1, vis2);
            }
        }
        return count;
    }
};