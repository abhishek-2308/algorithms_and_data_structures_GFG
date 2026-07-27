/* Structure of tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Solution {
    private:
    void get_Ans(Node* root, unordered_map<int, vector<int>> &mp, int lev){
        if(!root)return;
        mp[lev].push_back(root->data);
        get_Ans(root->left, mp, lev+1);
        get_Ans(root->right, mp, lev+1);
    }
  public:
    int maxLevelSum(Node* root) {
        // code here
        unordered_map<int, vector<int>> mp;
        get_Ans(root, mp, 0);
        int ans=-1;
        for(auto i: mp){
            ans= max(ans, accumulate(i.second.begin(), i.second.end(), 0));
        }
        return ans;
    }
};