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
    pair<bool, int> get_ans(Node* root){
        if(!root)return make_pair(1, 0);
        pair<bool, int> left= get_ans(root->left);
        pair<bool, int> right= get_ans(root->right);
        if(left.second==0 and right.second==0){
            return make_pair(true, left.second+ right.second+ root->data);
        }
         if( !left.first or  left.second + right.second != root->data){
            return make_pair(false, left.second+ right.second + root->data);
        }
        if(left.first and left.second + right.second == root->data){
            return make_pair(true,  left.second+ right.second + root->data);
        }
        else{
            return make_pair(false, left.second+ right.second+ root->data);
        }
    }
  public:
    bool isSumTree(Node* node) {
        // code here
        return get_ans(node).first;
    }
};