/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
    private:
    int get_ans(Node* root, int &sum){
        if(!root)return 0;
        if(!root->left and !root->right){
            return root->data;
        }
        int left= get_ans(root->left, sum);
        int right= get_ans(root->right, sum);
        if(root->left and root->right){
            sum= max(sum, root->data + left + right);
            return root->data + max(left, right);
        }
        if(root->left and !root->right){
            return root->data  + left;
        }
        if(root->right and !root->left){
            return root->data + right;
        }
        // return INT_MAX;
    
    }
  public:
    int maxPathSum(Node *root) {
        // code here
        int sum= INT_MIN;
        int could_be_maxi= get_ans(root, sum);
        if(root->left and root->right)return sum;
        return max(could_be_maxi, sum);
    }
};