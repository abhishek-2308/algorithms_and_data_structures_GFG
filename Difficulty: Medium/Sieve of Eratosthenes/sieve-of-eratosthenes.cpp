class Solution {
  public:
    vector<int> sieve(int n) {
        // code here
        vector<int> ans;
        vector<int> is_prime(n+1, 1);
        for(int i=2; i<=n; i++){
            if(is_prime[i]){
                for(int j= i*2; j<=n; j= j+i){
                    is_prime[j]=0;
                }
                if(is_prime[i]){
                    ans.push_back(i);
                }
                
            }
        }
        return ans;
    }
};