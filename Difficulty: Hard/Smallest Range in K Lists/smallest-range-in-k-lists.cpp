class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& mat) {
        priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>>>pq;
        int maxi= INT_MIN;
        for(int i=0; i<mat.size(); i+=1){
            pq.push(make_pair(mat[i][0], make_pair(i, 0)));
            maxi= max(maxi, mat[i][0]);
        }
        vector<int> ans(2, -1);
        ans[0]= pq.top().first;
        ans[1]= maxi;
        while(!pq.empty() and pq.size()==mat.size()){
            pair<int, pair<int, int>> top= pq.top();
            pq.pop();
            int ele= top.first;
            int row= top.second.first;
            int col= top.second.second;
            if(col+1 < mat[row].size()){
                maxi= max(maxi, mat[row][col+1]);
                pq.push(make_pair(mat[row][col+1], make_pair(row, col+1)));
                int mini= pq.top().first;
                if(maxi- mini <  ans[1]-ans[0]){
                   ans [0]= mini; 
                    ans[1]= maxi;
                }
                
            }
            
        }
        return ans;
        
        
    }
};