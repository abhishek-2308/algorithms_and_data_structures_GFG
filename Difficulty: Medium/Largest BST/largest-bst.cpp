/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class store{
    public:
    int maxi;
    int mini;
    int count;
    bool isBst;
};
class Solution {
    private:
    store get_the_Largest_bst(Node* root, int &ans){
        if(!root){
            return {INT_MIN, INT_MAX, 0, 1};
        }
        store left= get_the_Largest_bst(root->left, ans);
        store right= get_the_Largest_bst(root->right, ans);
        store curr_ans;
        curr_ans.count= left.count+ right.count + 1;
        if(left.isBst and right.isBst and root->data > left.maxi and root->data < right.mini){
            curr_ans.isBst= 1;
        }
        else{
            curr_ans.isBst= 0;
        }
        curr_ans.maxi= max(root->data, right.maxi);
        curr_ans.mini= min(root->data, left.mini);
        if(curr_ans.isBst){
            ans= max(ans, curr_ans.count);
            
        }
        return curr_ans;
    }
  public:
    int largestBst(Node *root) {
        // code here
        int ans=0;
        get_the_Largest_bst(root, ans);
        return ans;
        
    }
};