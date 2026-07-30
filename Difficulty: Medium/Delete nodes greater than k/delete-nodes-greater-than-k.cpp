/*The node structure
struct Node {
int data;
Node * right, * left;
};*/

class Solution {
    private:
    Node* delete_node_from_tree_greater_then_k(Node* root, int &k){
        if(!root)return nullptr;
        if(root->data>=k){
            return delete_node_from_tree_greater_then_k(root->left, k);
        }
        root->right= delete_node_from_tree_greater_then_k(root->right, k);
        return root;
    }
  public:
    /*The function should return the root of the modified tree*/
    Node* deleteNode(Node* root, int k) {
        // Your code here
        return delete_node_from_tree_greater_then_k(root, k);
    }
};