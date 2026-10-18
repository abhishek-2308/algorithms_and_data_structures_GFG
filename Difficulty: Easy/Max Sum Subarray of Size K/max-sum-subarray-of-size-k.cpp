class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int maxi=0;
        int right=0, left= 0, sum=0;
        int len=0;
        while(right < arr.size()){
            sum+= arr[right];
            while(right-left +1 > k){
                sum= sum- arr[left];
                left++;
            }
            maxi= max(maxi, sum);
            right++;
        }
        return maxi;
    }
};