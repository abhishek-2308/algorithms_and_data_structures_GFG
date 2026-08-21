/*
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
    int getAns(int &res, Node* root){
        if(!root)return INT_MAX;
        if(!root->left  && !root->right)return root->data;
        int value= min(getAns(res, root->left), getAns(res, root->right));
        res= max(res, root->data - value);
        return min(root->data, value);
    }
  public:
    int maxDiff(Node* root) {
       
        int res=INT_MIN;
        getAns(res, root);
        return res;
        
    }
};