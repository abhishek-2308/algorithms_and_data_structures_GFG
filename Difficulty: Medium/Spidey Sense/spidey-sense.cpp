class Solution {
  public:
    vector<vector<int>> findDistance(vector<vector<char>>& mat) {
        // code here
        vector<vector<int>> ans(mat.size(), vector<int> (mat[0].size(), -2));
        queue<pair<int, pair<int, int>>> q;
        for(int i=0; i<mat.size(); i+=1){
            for(int j=0; j<mat[0].size(); j+=1){
                if(mat[i][j]=='B'){
                    q.push(make_pair(0, make_pair(i, j)));
                    ans[i][j]= 0;
                }
            }
        }
        if(q.empty()){
            for(int i=0; i<mat.size(); i+=1){
                for(int j=0; j<mat[i].size(); j+=1){
                    ans[i][j]= -1;
                }
            }
            return ans;
        }
        while(!q.empty()){
            pair<int, pair<int, int>> front= q.front();
            q.pop();
            int dist= front.first;
            int i= front.second.first;
            int j= front.second.second;
            //check all foriur direction
            if(i-1 >=0 and mat[i-1][j]=='O' and ans[i-1][j]==-2){
                ans[i-1][j]= dist+1;
                q.push(make_pair(dist+1, make_pair(i-1, j)));
            }
            if(i+1< mat.size() and mat[i+1][j]=='O'  and ans[i+1][j]==-2){
                q.push(make_pair(dist+1, make_pair(i+1, j)));
                ans[i+1][j]= dist+1;
            }
            if(j-1 >=0 and mat[i][j-1]=='O'  and ans[i][j-1]==-2){
                q.push(make_pair(dist+1, make_pair(i, j-1)));
                ans[i][j-1]= dist+1;
            }
            if(j+1< mat[0].size() and mat[i][j+1]=='O' and ans[i][j+1]==-2){
                q.push(make_pair(dist+1, make_pair(i, j+1)));
             ans[i][j+1]= dist+1;   
            }
        }
        for(int i=0; i< mat.size(); i+=1){
            for(int j=0; j<mat[0].size(); j+=1){
                if(mat[i][j]=='W'){
                    ans[i][j]= -1;
                }
                else if(mat[i][j]=='O' and ans[i][j]==-2){
                    ans[i][j]= -1;
                }
            
            }
        }
        return ans;
    }
};