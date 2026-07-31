class Solution {
    private:

    bool check(vector<int> &mp, string &s){
        int target= -1;
        for(auto i: mp){
            if(i==0)continue;
            else if(target == -1){
                target=i;
            }
            else if(target != i)return false;
        }
        return 1;
    }
  public:
    bool sameFreq(string& s) {
        // code here
            vector<int> mp(26, 0);
        for(char ch: s){
            mp[ch-'a']++;
        }
        if(check(mp, s)){
            return 1;
        }
        for(int i=0; i<26; i++){
            if(mp[i]==0)continue;
            mp[i]--;
            if(check(mp, s)){
                return 1;
            }
            mp[i]++;
            
        }
        return false;
    }
};