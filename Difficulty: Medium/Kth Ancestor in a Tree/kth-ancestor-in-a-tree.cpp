/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
class Solution {
    private:
    int getAns(Node* root, int &k, int node, int &ans){
        if(!root)return false;
        if(node==root->data)return true;;
        bool left= getAns(root->left, k, node, ans);
        if(left){
            k--;
            if(k==0){
                ans= root->data;
            }
            return true;
        }
        bool right= getAns(root->right, k, node,ans);
        if(right){
            k--;
            if(k==0){
                ans= root->data;
            }
            return true;
        }
        return false;
        
    }
  public:
    int kthAncestor(Node *root, int k, int node) {
        // Code here
        int  ans=-1;
        getAns(root, k, node, ans);
    
        return ans;
    }
};
