class Solution {
	private:
	bool dfs(int node, vector<int> &vis, vector<int> adj[], int par) {
		vis[node] = 1;
		
		for (auto nbr : adj[node]) {
			if (!vis[nbr]) {
				if (dfs(nbr, vis, adj, node))
					return true;
			}
			else if (nbr != par) {
				return true;
			}
		}
		
		return false;
	}
	public:
	int isTree(int n, int m, vector<vector<int>> &edges) {
		vector<int> adj[n];
		for (auto i: edges) {
			int u = i[0];
			int v = i[1];
			if (u == v)return false;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> vis(n + 1, 0);
		if (dfs(0, vis, adj, -1))
			return false;
		for(int i=0; i<n; i++){
		    if(!vis[i])return false;
		}
		return 1;
		
	}
};
