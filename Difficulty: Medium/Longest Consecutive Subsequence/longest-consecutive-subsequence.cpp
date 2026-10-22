class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        // code here
        unordered_set<int> st;
        for(auto i: arr){
            st.insert(i);
        }
        int longest= 1;
        for(auto i: st){
            if(st.find(i-1)==st.end()){
                int count=1;
            int ele= i;
            while(st.find(ele+1) != st.end()){
                count+=1;
                ele+=1;
            }
            longest= max(longest, count);
            }
            
        }
        return longest;
    }
};