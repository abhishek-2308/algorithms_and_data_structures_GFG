class Solution {
    private:
    int get_gcd(int a, int b){
        if(a==b)return a;
        if(a<b){
            return get_gcd(a, b-a);
        }
        return get_gcd(a-b, b);
    }
  public:
    int maxBinTreeGCD(vector<vector<int>> &arr) {
        // code here
       unordered_map<int, vector<int>> mp;
       for(auto i: arr){
           int u= i[0];
           int v= i[1];
           mp[u].push_back(v);
       }
       int ans= 0;
       for(auto i: mp){
           if(i.second.size()==2){
               int num1= i.second[0];
               int num2= i.second[1];
               int gcd_= get_gcd(num1, num2);
               ans= max(ans, gcd_);
           }
           
       }
       return ans;
    }
};
