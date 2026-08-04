class Solution {
public:
    void solve(long long n, vector<long long> &ans) {
        ans.push_back(n);

        if (n == 1)
            return;

        if (n % 2 == 0)
            solve(sqrt(n), ans);
        else
            solve(n * sqrt(n), ans);
    }

    vector<long long> jugglerSequence(long long n) {
        vector<long long> ans;
        solve(n, ans);
        return ans;
    }
};