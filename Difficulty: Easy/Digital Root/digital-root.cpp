class Solution {
    private:
    int get_ans(int n){
        
        if(!n)return 0;
        return n %10 + get_ans(n/10);
    }
  public:
    int digitalRoot(int n) {
        // code here
        while(true){
           int ans= get_ans(n); 
           if(ans<10){
               return ans;
           }
           n= ans;
        }
        return -1;
        
    }
};