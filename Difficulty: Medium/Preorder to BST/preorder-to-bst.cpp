/* Structure of a Tree Node
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    private:
    Node* get_ans(vector<int> &pre, int &index, int mini, int maxi){
        if(index>=pre.size())return nullptr;
        if(pre[index]<mini or pre[index]>maxi)return nullptr;
        Node* root= new Node(pre[index++]);
        root->left= get_ans(pre, index, mini, root->data);
        root->right= get_ans(pre, index, root->data, maxi);
        return root;
    }
  public:
    Node* preToBST(vector<int>& pre) {
        // code here
        int index= 0;
        return get_ans(pre, index, INT_MIN, INT_MAX);
    }
};