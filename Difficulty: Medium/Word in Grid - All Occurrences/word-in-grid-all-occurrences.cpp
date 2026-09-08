class Solution {
	private:
	bool is_possible_(int i, int j, int n, int m, int x, string &word, vector<vector<char>> &grid, char pivot) {
		if (x >= word.size())return 1;
		if (i < 0 || i >= n || j < 0 || j >= m ||
		grid[i][j] != word[x])return false;
		char ch = grid[i][j];
		if (pivot == 'L') {
			grid[i][j] = '*';
			bool left = is_possible_(i, j - 1, n, m, x + 1, word, grid, pivot);
			grid[i][j] = ch;
			return left;
		}
		if (pivot == 'R') {
			grid[i][j] = '*';
			bool right = is_possible_(i, j + 1, n, m, x + 1, word, grid, pivot);
			grid[i][j] = ch;
			return right;
		}
		if (pivot == 'U') {
			grid[i][j] = '*';
			bool UP = is_possible_(i - 1, j, n, m, x + 1, word, grid, pivot);
			grid[i][j] = ch;
			return UP;
		}
		if (pivot == 'D') {
			grid[i][j] = '*';
			bool down = is_possible_(i + 1, j, n, m, x + 1, word, grid, pivot);
			grid[i][j] = ch;
			return down;
		}
		if (pivot == 'P') {
			grid[i][j] = '*';
			bool leftUpD = is_possible_(i - 1, j - 1, n, m, x + 1, word, grid, pivot);
			grid[i][j] = ch;
			return leftUpD;
		}
		if (pivot == 'Q') {
			grid[i][j] = '*';
			bool rightUpD = is_possible_(i + 1, j + 1, n, m, x + 1, word, grid, pivot);
			grid[i][j] = ch;
			return rightUpD;
		}
		if (pivot == 'M') {
			grid[i][j] = '*';
			bool leftDowD = is_possible_(i + 1, j - 1, n, m, x + 1, word, grid, pivot);
			grid[i][j] = ch;
			return leftDowD;
		}
		if (pivot == 'S') {
			grid[i][j] = '*';
			bool rightUpDD = is_possible_(i - 1, j + 1, n, m, x + 1, word, grid, pivot);
			grid[i][j] = ch;
			return rightUpDD;
		}
		
	}
	public:
	vector<vector<int>> searchWord(vector<vector<char>> grid, string word) {
		// Code here
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> ans;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				if (grid[i][j] == word[0]) {
					///all 8 durection
					bool left = is_possible_(i, j, n, m, 0, word, grid, 'L');
					bool right = is_possible_(i, j, n, m, 0, word, grid, 'R');
					bool up = is_possible_(i, j, n, m, 0, word, grid, 'U');
					bool down = is_possible_(i, j, n, m, 0, word, grid, 'D');
					bool leftUpD = is_possible_(i, j, n, m, 0, word, grid, 'P');
					bool rightUpD = is_possible_(i, j, n, m, 0, word, grid, 'Q');
					bool leftDowD = is_possible_(i, j, n, m, 0, word, grid, 'M');
					bool rightUpDD = is_possible_(i, j, n, m, 0, word, grid, 'S');
					if (left || right || up || down || leftUpD || rightUpD || leftDowD || rightUpDD) {
						ans.push_back({i, j});
					}
				}
			}
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
};
