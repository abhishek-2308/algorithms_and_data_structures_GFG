class Solution {
  public:
    bool isPrime(int n) {
        // code here
        if(n <=2){
            return false;
            
        }
        int count=0;
        for(int i=1; i*i <=n; i+=1){
            if(n %i==0){
                count++;
                if( i != (n/i)){
                    count++;
                }
            }
            if(count>2)return false;
        }
        return 1;
    }
};
