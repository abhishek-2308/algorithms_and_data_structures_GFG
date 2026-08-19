/* Structure of a Binary Tree Node
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
    void get_ans(Node* root, int &k, int &ans){
        if(!root)return ;
        get_ans(root->right, k, ans);
        if(--k==0){
            ans= root->data;
        }
        
        get_ans(root->left, k, ans);
    }
  public:
    int kthLargest(Node *root, int k) {
        // code here
        int ans= -1;
        get_ans(root, k, ans);
        return ans;
    }
};