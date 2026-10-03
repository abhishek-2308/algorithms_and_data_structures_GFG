class Solution {
	public:
	vector<int> minHeightRoot(int V, vector<vector<int>> & edges) {
		// Code here
		vector<int> indeg(V, 0);
		vector<int> adj[V];
		queue<int> q;
		for (auto i: edges) {
			int u = i[0];
			int v = i[1];
			indeg[u]++;
			indeg[v]++;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 0; i<V; i += 1) {
			if (indeg[i] == 1) {
				q.push(i);
			}
		}
		// vector<int> ans
		int remaining = V;
		while (remaining>2) {
			int size = q.size();
			remaining = remaining - size;
			while (size--) {
				int node = q.front();
				q.pop();
				for (auto nbr : adj[node]) {
					indeg[nbr]--;
					if (indeg[nbr] == 1) {
						q.push(nbr);
					}
				}
			}
		}
		vector<int> ans;
		while (!q.empty()) {
			ans.push_back(q.front());
			q.pop();
		}
// 		return ans;
if(ans.empty())return {0};
return ans;
	}
};
