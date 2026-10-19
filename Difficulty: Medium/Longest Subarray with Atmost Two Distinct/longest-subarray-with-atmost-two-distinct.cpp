class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int left=0;
        int right= 0;
        // int dis=0;
        int len=0;
        unordered_map<int, int> mp;
        while(right < arr.size()){
            mp[arr[right]]++;
            while((int)mp.size()>2){
                mp[arr[left]]--;
                if(mp[arr[left]]==0){
                    mp.erase(arr[left]);
                }
                 left++;
            }
            
            len= max(len, right-left+1);
            right+=1;
            
        }
        return len;
    }
};