class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        for(int i=0; i<dist.size(); i+=1){
            for(int j= 0; j< dist.size(); j+=1){
                for(int k= 0; k<dist.size(); k+=1){
                    if(dist[j][i]==1e8 or dist[i][k]==1e8){
                        continue;
                    }
                    if(dist[j][i] + dist[i][k] < dist[j][k]){
                        dist[j][k]= dist[j][i] + dist[i][k];
                    }
                }
            }
        }
    }
};