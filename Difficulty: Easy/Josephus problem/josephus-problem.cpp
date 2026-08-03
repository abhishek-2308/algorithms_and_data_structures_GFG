class Solution {
    private:
    void get_ans(int n, int k, int index, vector<int> &vec,  int &ans){
        if(vec.size()==1){
            ans= vec.back();
            return;
        }
        index= (index+k) % vec.size();
        vec.erase(vec.begin()+index);
        get_ans(n, k, index, vec, ans);
    }
  public:
    int josephus(int n, int k) {
        // code here
        vector<int> vec;
        for(int i=1; i<=n; i++){
            vec.emplace_back(i);
        }
       
        int ans=-1;
        int index=0;
        k= k-1;
        get_ans(n, k, index, vec, ans);
        return ans;
    }
};