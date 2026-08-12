// Method 1 Bruete Force///

class Solution {
    private:
    int find_ways_and_path(vector<vector<int>> &grid, int i, int j, int &maxi, int sum){
        if(i<0)return 0;
        if(i>=grid.size())return 0;
        if(j<0)return 0;
        if(j>=grid[i].size())return 0;
        if(i==grid.size()-1 and j==grid[i].size()-1){
            sum+=grid[i][j];
            maxi= max(maxi, sum);
            return 1;
        }
        int count=0;
        //right move karo only
        if(grid[i][j]==1){
            count+= find_ways_and_path(grid, i, j+1, maxi, sum+grid[i][j]);
            return count;
        }
        //down move karo
        if(grid[i][j]==2){
            count+= find_ways_and_path(grid, i+1, j, maxi,sum+grid[i][j]);
            return count;
        }
        //2 options hain
        if(grid[i][j]==3){
            count+=find_ways_and_path(grid, i, j+1, maxi,sum+grid[i][j])+ find_ways_and_path(grid, i+1, j,maxi, sum+grid[i][j]);
            return count;
        }
    }
  public:
    vector<int> findWays(vector<vector<int>>& grid) {
        // code here
        int maxi= 0;
        int sum=0;
        vector<vector<int>> dp(grid.size()+1, vector<int> (grid.size()+1, -1));
        int length= find_ways_and_path(grid, 0, 0, maxi, sum);
        vector<int> ans;
        ans.push_back(length);
        ans.push_back(maxi);
        return ans;
    }
};


// Method 2 Optimal and Expected......

class Solution {
	private:
	const int mod= 1e9 + 7;
	pair<int, int> get_ans(vector<vector<int>> &grid,int i,int j,vector<vector<pair<int, int>>> &dp) {
		
		if (i < 0 || i >= grid.size() ||j < 0 || j >= grid[0].size()) {
			return make_pair(0, 0);
		}
		if (i == grid.size() - 1 and j == grid[0].size() - 1) {
			return make_pair(1, grid[i][j]);
		}
		if (dp[i][j].first != -1) {
			return dp[i][j];
		}
		int path = 0;
		int maxi = 0;
		if (grid[i][j] == 1) {
			
			pair<int, int> right =get_ans(grid, i, j + 1, dp);
			
			path = right.first % mod;
			
			if (right.second != 0) {
				maxi = grid[i][j] + right.second;
			}
		}
		else if (grid[i][j] == 2) {
			
			pair<int, int> down =get_ans(grid, i + 1, j, dp);
			
			path = down.first %mod;
			
			if (down.second != 0) {
				maxi = grid[i][j] + down.second;
			}
		}
		else if (grid[i][j] == 3) {
			
			pair<int, int> right =get_ans(grid, i, j + 1, dp);
			
			pair<int, int> down =
			get_ans(grid, i + 1, j, dp);
			
			path = (right.first + down.first) %mod;
			
			if (right.second != 0) {
				maxi = max(maxi,grid[i][j] + right.second);
			}
			
			if (down.second != 0) {
	            maxi = max(maxi,grid[i][j] + down.second);
			}
		}
		
		return dp[i][j] = make_pair(path, maxi);
	}
	
	public:
	
	vector<int> findWays(vector<vector<int>> & grid) {
		
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<pair<int, int>>>dp(n,vector<pair<int, int>> (m, make_pair(-1, -1)));
		pair<int, int> result =get_ans(grid, 0, 0, dp);
		vector<int> ans;
		ans.push_back(result.first %mod);
		ans.push_back(result.second);
		
		return ans;
	}
};
