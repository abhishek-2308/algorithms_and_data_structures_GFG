class Solution {
    private:
    int get_ans(int n){
        if(!n)return 1;
        if(n==1)return 1;
        return n * get_ans(n-1);
    }
  public:
    int factorial(int n) {
        // code here
        return get_ans(n);
    }
};