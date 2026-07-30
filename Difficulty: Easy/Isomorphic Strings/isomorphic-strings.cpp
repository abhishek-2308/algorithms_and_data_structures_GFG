class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        vector<int>mp1(126, -1);
        vector<int> mp2(126, -1);
        if(s1.size()!=s2.size())return false;
        for(int i=0; i<s1.size(); i++){
            if(mp1[s1[i]] != mp2[s2[i]])return false;
            mp1[s1[i]]= mp2[s2[i]]=i;
        }
        return 1;
    }
};