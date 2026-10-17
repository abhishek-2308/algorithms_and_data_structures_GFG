class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        // code here
        int  i=0;
        int maxi_one= INT_MIN;
        int maxi_zero=INT_MIN;
        int count_one=0;
        int count_zero=0;
        
        while(i < arr.size()){
            if(arr[i]==1){
                count_one++;
                count_zero=0;
            }
            else if(arr[i]==0){
                count_zero++;
                count_one=0;
            }
            maxi_one= max(count_one, maxi_one);
            maxi_zero= max(count_zero, maxi_zero);
            i+=1;
        }
        return max(maxi_zero, maxi_one);
    }
};