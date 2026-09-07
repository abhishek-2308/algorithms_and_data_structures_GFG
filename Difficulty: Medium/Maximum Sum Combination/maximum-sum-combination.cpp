class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(), a.end(), [](int &a, int &b){
            return a>b;
        });
        sort(b.begin(), b.end(), [](int &a, int &b){
            return a>b;
        });
        priority_queue<pair<int, pair<int, int>>> pq;
        int n= a.size();
        int m= b.size();
        for(int  i=0; i<m; i++){
            pq.push(make_pair(a[0]+b[i], make_pair(0, i)));
        }
        vector<int>ans;
        while(k-- and !pq.empty()){
            pair<int, pair<int, int>> top= pq.top();
            pq.pop();
            
            int maxi_= top.first;
            int i= top.second.first;
            int j= top.second.second;
            ans.push_back(maxi_);
            if(i+1< n){
                pq.push(make_pair(a[i+1]+ b[j], make_pair(i+1, j)));
            }
            
        }
        return ans;
        
    }
};