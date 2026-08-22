class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // code here
        int l=0;
        int r=0;
        int sum=0;
        int ans=INT_MAX;
        while(r<arr.size()){
          sum+=arr[r];
          while(sum>x){
              sum= sum- arr[l];
              ans= min(ans, r-l+1);
              l++;

          }
          r++;
        } 
        return ans==INT_MAX ? 0 : ans; 
    }
};