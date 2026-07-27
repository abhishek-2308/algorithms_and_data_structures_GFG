/* Structure of a Tree Node
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
    private:
    void get_ans(Node* root, long long int curr, long long int &sum){
        if(!root)return;
        if(root->left==nullptr and root->right==nullptr){
            curr= curr*10 + root->data;
            sum+=curr;
            return;
        }
        get_ans(root->left, curr*10 + root->data, sum);
        get_ans(root->right, curr*10 + root->data, sum);
    }
  public:
    int treePathsSum(Node *root) {
        long long int sum= 0;
        long long int curr= 0;
        get_ans(root, curr, sum);
        return (int)sum;
    }
};