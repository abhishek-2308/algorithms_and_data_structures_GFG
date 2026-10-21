class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        int maxi= 1;
        int tem_count=1;
        int i=1;
        while(i < arr.size()){
            if(arr[i-1]== arr[i])
            {i++;
            
            continue;}
            if(arr[i-1]+1== arr[i]){
                tem_count++;
            }
            else{
                tem_count=1;
            }
            maxi= max(maxi, tem_count);
            i+=1;
        }
        return maxi;
    }
};