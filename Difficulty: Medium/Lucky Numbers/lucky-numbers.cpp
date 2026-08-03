class Solution {
    private:
    bool get_is_Lucky_or_Not(int position, int counter){
        if(position < counter)return 1;
        
        if(position % counter==0)return false;
        
        position= position- (position / counter);
        
        
        return get_is_Lucky_or_Not(position, counter+1);
    }
  public:
    bool isLucky(int n) {
        // code here
        //starting wala Postion is 2 so start with 2 and in everyiteratuon inclrrrase your counbt+1
        return get_is_Lucky_or_Not(n, 2);
    }
};