/* Tree Node structure
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};*/

class Solution {
    private:
    bool get_ans(Node* root, int mini, int maxi){
        if(!root)return 0;
        if(!root->left and !root->right){
         if(root->data - mini==1 and maxi- root->data==1)return 1;
         return false;
        }
        bool left= get_ans(root->left, mini, root->data);
        bool right= get_ans(root->right, root->data, maxi);
        return left || right;
    }
  public:
    bool isDeadEnd(Node *root) {
        // Code here
     return get_ans(root, 0, INT_MAX);
        // ret
    }
};