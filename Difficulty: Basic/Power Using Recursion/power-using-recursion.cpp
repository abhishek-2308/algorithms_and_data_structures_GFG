class Solution {
    private:
    int get_ans(int n, int p){
        if(p==0)return 1;
        if(p==1)return n;
        return n*get_ans(n, p-1);
    }
  public:
    int recursivePower(int n, int p) {
        // code here
        return get_ans(n, p);
    }
};
