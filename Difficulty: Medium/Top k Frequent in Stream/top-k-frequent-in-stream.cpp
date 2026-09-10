class Solution {
  public:
    vector<vector<int>> kTop(int k, vector<int>& arr) {
        // code here
       vector<vector<int>> ans;
       map<int, int> mp;
       for(int i=0; i<arr.size(); i+=1){
           mp[arr[i]]++;
           vector<pair<int,  int>> vec;
           for(auto it: mp){
               vec.push_back(make_pair(it.first, it.second));
           }
           sort(vec.begin(), vec.end(), [](pair<int, int> &a, pair<int, int> &b){
               if(a.second != b.second)return a.second > b.second;
               return a.first < b.first;
           });
           
           vector<int> v;
           for(int j=0; j<vec.size(); j+=1){
               v.push_back(vec[j].first);
               if(v.size()==k){
                   break;
               }
           }
           ans.push_back(v);
       }
       return ans;
    }
};