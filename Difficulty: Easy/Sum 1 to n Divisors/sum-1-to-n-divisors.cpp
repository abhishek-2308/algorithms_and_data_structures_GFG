class Solution {
    private:
    int get_ans(int n){
        int sum=0;
        for(int i=1; i*i <=n; i++){
            if(n %i==0){
                sum+=i;
                if(i != (n/i)){
                    sum+= n/i;
                }
            }
        }
        return sum;
    }
  public:
    long long sumOfDivisors(long long n) {
        // Code here
        long long ans=0;
        for(int i=1; i<=n;  i++){
            ans+= get_ans(i);
        }
        return ans;
    }
};