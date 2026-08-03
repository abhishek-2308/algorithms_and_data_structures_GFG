class Solution {
    private:
    int get_ans(int n){
        if(n==0)return 0;
        return 1+ get_ans(n/10);
    }
  public:
    int countDigits(int n) {
        // Code here
        return get_ans(n);
    }
};