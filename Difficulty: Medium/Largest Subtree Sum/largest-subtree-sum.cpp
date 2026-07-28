/* structure of binary tree node
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
    int get_ans(Node* root, int &maxi){
        if(!root)return 0;
        int left= get_ans(root->left, maxi);
        int right= get_ans(root->right, maxi);
        int sum= left + right + root->data;
        maxi= max(maxi, sum);
        return sum;
    }
  public:
    int maxSubtreeSum(Node* root) {
        // code here
        int maxi= INT_MIN;
        get_ans(root, maxi);
        return maxi;
    }
};
