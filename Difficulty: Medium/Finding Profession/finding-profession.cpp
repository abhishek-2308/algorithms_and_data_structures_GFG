class Solution {
  public:
    string profession(int level, int pos) {
        // code here
        int change= __builtin_popcount(pos-1);
        if(change & 1){
            return "Doctor";
        }
        return "Engineer";
    }
};