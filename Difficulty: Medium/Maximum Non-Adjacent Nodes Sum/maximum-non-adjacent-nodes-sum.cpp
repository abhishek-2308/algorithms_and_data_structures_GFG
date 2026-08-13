/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
    private:
    int get_ans(Node* root, unordered_map<Node*, int> &dp){
        if(!root){
            return 0;
            
        }
        if(dp.find(root) != dp.end()){
            return dp[root];
        }
        int include= root->data;
        if(root->left){
            include= include+ get_ans(root->left->left, dp) + get_ans(root->left->right, dp);
        }
        if(root->right){
            include= include + get_ans(root->right->left, dp) + get_ans(root->right->right, dp);
        }
        int exclude= 0;
        exclude= exclude+ get_ans(root->left, dp);
        exclude= exclude+ get_ans(root->right, dp);
        return dp[root]= max(include, exclude);
    }
  public:
    int getMaxSum(Node *root) {
        // code here
        unordered_map<Node*, int> dp;
        return get_ans(root, dp);
    }
};