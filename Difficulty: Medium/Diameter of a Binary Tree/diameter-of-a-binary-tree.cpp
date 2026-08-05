/*Structure of binary tree Node 
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
    int get_height(Node* root){
        if(!root)return 0;
        return max(get_height(root->left), get_height(root->right))+1;
    }
    private:
    void get_maxi_depth(Node* root, int &maxi){
        if(!root)return ;
        int heightOfTree= get_height(root->left) + get_height(root->right)+1;
        maxi= max(maxi, heightOfTree);
        get_maxi_depth(root->left, maxi);
        get_maxi_depth(root->right, maxi);
    }
  public:
    int diameter(Node* root) {
        // code here
        int maxi= -1;
        get_maxi_depth(root, maxi);
        return maxi-1;
    }
};