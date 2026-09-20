// User function Template for C++

class Solution {
    private:
    const int inf= 1e8;
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        //make the destinatiom of the arrar
        vector<int> dist(V, inf);
        dist[src]=0;
        //relax upto tghe N-1 times
        for(int i=0; i<V-1; i++){
            bool isChange= false;
            for(auto i: edges){
                int u= i[0];
                int v= i[1];
                int wt= i[2];
                if(dist[u]==inf)continue;
                else{
                    if(dist[u] + wt < dist[v]){
                        dist[v]= dist[u] + wt;
                        isChange= true;
                    }
                }
            }
            if(!isChange)return dist;
        }
        
        // // for(auto i: dist){
        // //     cout<<i<<endl;
        // // }
        // cout<<endl;
        //detct the cycle if it is 'prrsent bnot psossibke ti abs
        for(int  i=0; i<edges.size(); i++){
            int u= edges[i][0];
            int v= edges[i][1];
            int wt= edges[i][2];
            if(dist[u]==inf)continue;
            
            if(dist[u] + wt < dist[v]){
                return {-1};
            }
            
        }
        return dist;
    }
};
