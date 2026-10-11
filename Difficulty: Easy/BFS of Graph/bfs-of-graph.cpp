class Solution {
    private:
    void getBfs(vector<int> &ans, vector<vector<int>> &adj, vector<int> &vis, queue<int> &q){
   if(q.empty())
   return ;
    int top= q.front();
    q.pop();
    ans.push_back(top);
    for(auto i: adj[top]){
        if(!vis[i]){
            q.push(i);
            vis[i]= 1;
        }
    }
    getBfs(ans, adj, vis, q);
    }
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        queue<int> q;
        q.push(0);
       
        vector<int> vis(adj.size(), false);
        vector<int> ans;
         vis[0]=1;
        getBfs(ans, adj, vis, q);
        return ans;
    }
};