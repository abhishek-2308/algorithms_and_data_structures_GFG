class Solution {
  public:
    bool isPerfect(int n) {
        // code here
        if(n==1)return false;
        int sum=1;
        for(int i=2; i<= sqrt(n); i+=1){
            if(n % i==0){
                sum+=i;
                if( i !=  n/i){
                    sum+= n/i;
                }
            }
        }
        return sum== n;
    }
};