/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    private:
    int get_ans(Node* root, int &k){
        if(!root)return -1;
        int left= get_ans(root->left, k);
        k--;
        if(k==0){
            return root->data;
        }
        if(left != -1){
            return left;
        }
        return get_ans(root->right, k);
    }
  public:
    int kthSmallest(Node *root, int k) {
        // code here
        return get_ans(root, k);
    }
};