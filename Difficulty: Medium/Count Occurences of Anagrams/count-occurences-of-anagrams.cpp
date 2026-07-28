// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        vector<int> txtc(26, 0);
        vector<int> patc(26, 0);
        // int count=0;
        for(int i=0; i<pat.size(); i++){
            patc[pat[i]-'a']++;
        txtc[txt[i]-'a']++;
            
        }
        // for(int i=0; i<pat.size(); i++){
        //     txtc[txt[i]-'a']++;
        // }
        int count=0;
        if(txtc==patc)
        count++;
        int k= pat.size();
        for(int i= k; i<txt.size(); i++){
            txtc[txt[i]-'a']++;
            int index= txt[i-k]-'a';
            txtc[index]--;
            if(txtc==patc)
            count++;
        }
        return count;
    }
};