class Solution {
    private:
    int get_ans(int n){
        if(!n)return 0;
        return n+ get_ans(n-1);
    }
  public:
    int recursiveSum(int n) {
        // Recursively sum from 1 to n and return
        // code here
        return get_ans(n);
    }
};