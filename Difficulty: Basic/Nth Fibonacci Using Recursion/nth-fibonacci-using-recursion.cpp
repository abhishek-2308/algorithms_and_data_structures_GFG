class Solution {
    private:
    int get_fib(int n){
        if(n<=1)return n;
        return get_fib(n-1) + get_fib(n-2);
    }
  public:
    int nthFibonacci(int n) {
        // code here
        return get_fib(n);
    }
};