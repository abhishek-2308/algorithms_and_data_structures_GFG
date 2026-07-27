/* Definition for Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
    private:
    int get_ans(Node* root, char left_or_right){
        if(!root)return 0;
        if(root->left==nullptr and root->right==nullptr and left_or_right=='L'){
            return root->data;
        }
        int left= get_ans(root->left, 'L');
        int right= get_ans(root->right, 'R');
        return left + right;
    }
  public:
    int leftLeavesSum(Node *root) {
        // code here
        return get_ans(root, 'I');
    }
};