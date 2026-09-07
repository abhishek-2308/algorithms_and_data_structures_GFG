class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        vector<int> ans;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>>> pq;
        for(int i=0; i< mat.size(); i++){
            pq.push(make_pair(mat[i][0], make_pair(i, 0)));
        }
        while(!pq.empty()){
            pair<int, pair<int, int>> top= pq.top();
            pq.pop();
            int maxi= top.first;
            int i= top.second.first;
            int j= top.second.second;
            ans.push_back(maxi);
            if(j+1< mat[i].size()){
                pq.push(make_pair(mat[i][j+1], make_pair(i, j+1)));
            }
        }
        return ans;
    }
};