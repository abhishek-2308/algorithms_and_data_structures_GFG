class Solution {
private:
    bool get_ans(vector<int> &pre, int &index, vector<int> &ans,
                 int mini, int maxi) {

        if (index >= pre.size() || 
            pre[index] <= mini || pre[index] >= maxi) {
            return false;
        }

        int curr = pre[index++];

        bool left = get_ans(pre, index, ans, mini, curr);
        bool right = get_ans(pre, index, ans, curr, maxi);

        if (!left && !right) {
            ans.push_back(curr);
        }

        return true;
    }

public:
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> ans;
        int index = 0;

        get_ans(preorder, index, ans, INT_MIN, INT_MAX);

        return ans;
    }
};