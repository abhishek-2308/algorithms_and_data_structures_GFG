class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int  m= arr2.size();
        for(int i=0; i<m; i++){
            pq.push(make_pair(arr1[0]+ arr2[i], make_pair(0, i)));
        }
        while(k-- and !pq.empty()){
            pair<int, pair<int,int>> top=  pq.top();
            int x= top.first;
            int i= top.second.first;
            int j= top.second.second;
            pq.pop();
            ans.push_back({arr1[i],arr2[j]});
            if(i+1< arr1.size()){
                pq.push(make_pair(arr1[i+1]+ arr2[j], make_pair(i+1, j)));
                
            }
            
            
        }
        return ans;
        
    }
};
