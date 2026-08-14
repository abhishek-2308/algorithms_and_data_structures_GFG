class Solution {
    private:
    bool get_ans(vector<int> &temp, int index, int target, vector<vector<int>> &dp){
      if (target == 0)
      return true;
      if (index == 0)
      return target == temp[0];
       if(dp[index][target]!=-1)return dp[index][target];
       bool take= false;
       if (temp[index] <= target){
        take= get_ans(temp, index-1, target- temp[index], dp);       
       }
        bool notTake= get_ans(temp, index-1, target, dp);
        return dp[index][target]=take || notTake;
        
    }
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        // code here
        vector<int> temp;
        temp.push_back(s);
        int sum= s;
        sum+=arr[0];
        temp.push_back(sum);
        sum= accumulate(temp.begin(), temp.end(), 0);
        for(int i=1; i<arr.size(); i++){
            int dup= sum;
            sum+=arr[i];
            temp.push_back(sum);
            sum+=dup;
            
            
        }
        // vector<vector<int>> dp(temp.size()+1, vector<int> (x+1, -1));
        // return get_ans(temp, temp.size()-1, x, dp);
        
        // vector<int> temp;
        // temp.push_back(s);
        // int sum = s;
        // sum += arr[0];
        // temp.push_back(sum);
        // sum = accumulate(temp.begin(), temp.end(), 0);
        // for (int i = 1; i < arr.size(); i++) {
        //     int dup = sum;
        //     sum += arr[i];
        //     temp.push_back(sum);
        //     sum += dup;
        // }
        // vector<bool> dp(x + 1, false);
        // dp[0] = true;
        // for (int num : temp) {
        //     for (int target = x; target >= num; target--) {
        //         dp[target] = dp[target] || dp[target - num];
        //     }
        // }

        // return dp[x];
        
        for(int i= temp.size()-1; i>=0; i--){
            if(temp[i]<=x){
                x= x-temp[i];
            }
            if(x==0)return true;
        }
        return false;

    }
    
    
};