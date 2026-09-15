class Solution {
    private:
    const  int mod= 1000;
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int, int>> q;
        vector<int> vis(10000, 0);
        q.push(make_pair(start, 0));
        vis[start]=1;
        while(!q.empty()){
            
            // pair<int, int>tope= q.top();
            pair<int, int> top= q.front();
            int node= top.first;
            int steps= top.second;
            q.pop();
            if(node== end)return steps;
            for(auto i: arr){
                int mul= (i*node) % mod;
                if(!vis[mul]){
                    q.push(make_pair(mul, steps+1));
                    vis[mul]=1;
                    
                }
            }
            
        }
        return -1;
    }
};