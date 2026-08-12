/* Structure of binary tree node
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
    Node* get_LCA(Node* root, int n1, int n2){
        if(!root)return nullptr;
        if(root->data==n1 or root->data==n2)return root;
        Node* left= get_LCA(root->left, n1, n2);
        Node* right= get_LCA(root->right, n1, n2);
        if(!left and right){
            return right;
        }
        if(!right and left){
            return left;
        }
        if(right and left)return root;
    }
  public:
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        return get_LCA(root, n1, n2);
    }
};