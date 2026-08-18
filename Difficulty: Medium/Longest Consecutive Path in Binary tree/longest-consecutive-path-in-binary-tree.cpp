/* Structure of Binary Tree Node
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
    int  get_ans(Node* root, int len){
        if(!root)return 0;
        int ans= len;
        if(root->left){
            if(root->left and root->data+1 == root->left->data){
                ans= max(ans, get_ans(root->left, len+1));
            }
            else{
                ans= max(ans, get_ans(root->left, 1));
            }
        }
        if(root->right){
            if(root->right and root->data + 1== root->right->data){
                ans= max(ans, get_ans(root->right, len+1));
            }
            else{
                ans= max(ans, get_ans(root->right, 1));
            }
        }
        return ans;
    }
  public:
    int longestConsecutive(Node* root) {
        // code here
        int ans= get_ans(root, 1);
        return ans==1? -1 : ans;
    }
};