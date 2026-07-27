/*
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
    bool getAns(Node* root, int maxi, int mini){
        if(!root)return true;
        if(root->data>mini and root->data<maxi){
            bool left= getAns(root->left, root->data, mini);
            bool right= getAns(root->right,maxi, root->data);
            return left && right;
        }else return false;
    }
  public:
    bool isBST(Node* root) {
        // code here
        return getAns(root, INT_MAX, INT_MIN);
    }
};