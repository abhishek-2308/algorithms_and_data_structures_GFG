/* BST Node Structure
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
}; */

class Solution {
    void get_inorder(Node* root, vector<int> &ans){
        if(!root)return;
        get_inorder(root->left, ans);
        ans.push_back(root->data);
        get_inorder(root->right, ans);
    }
    Node* make_tree(vector<int> &ans, int s, int e){
        if(s>e)return nullptr;
        int mid= s+(e-s)/2;
        Node* root= new Node(ans[mid]);
        root->left= make_tree(ans, s, mid-1);
        root->right= make_tree(ans, mid+1, e);
        return root;
    }
  public:
    Node* balanceBST(Node* root) {
        // Code here
        vector<int> ans;
        get_inorder(root, ans);
        int s= 0;
        int e= ans.size()-1;
        int mid= s+(e-s)/2;
        Node*  newRoot= new Node(ans[mid]);
        newRoot->left= make_tree(ans, s, mid-1);
        newRoot->right= make_tree(ans, mid+1, e);
        return newRoot;
    }
};