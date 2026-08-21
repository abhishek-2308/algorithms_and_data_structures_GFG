class Solution {
  public:
    int transform(string &s1, string &s2) {
        if (s1.size() != s2.size()) return -1;
        vector<int> hash(256, 0);
        for (int i = 0; i < s1.size(); i++) {
            hash[s1[i]]++;
            hash[s2[i]]--;
        }
        for (int i = 0; i < 256; i++) {
            if (hash[i] != 0) return -1;
        }

        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int ans = 0;
        while (i >= 0 && j >= 0) {

            if (s1[i] == s2[j]) {
                i--;
                j--;
            } else {
                ans++;
                i--;
            }
        }

        return ans;
    }
};