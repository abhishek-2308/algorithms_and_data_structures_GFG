class Solution {
    private:
    int count_freinds_pair(int n){
        if(n<=1)return 1;
        return count_freinds_pair(n-1) + (n-1)* count_freinds_pair(n-2);
    }
  public:
    int countFriendsPairings(int n) {
        // code here
        return count_freinds_pair(n);
    }
};
