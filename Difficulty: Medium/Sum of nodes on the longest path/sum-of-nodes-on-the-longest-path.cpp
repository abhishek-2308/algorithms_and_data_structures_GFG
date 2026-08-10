/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
    private:
    pair<int, int> longest_path_sum(Node* root){
        if(!root){
            return make_pair(0, 0);
        }
        pair<int, int> left= longest_path_sum(root->left);
        pair<int, int> right= longest_path_sum(root->right);
        pair<int, int> ans;
        if(left.first==right.first){
            return make_pair(max(left.first, right.first)+1,max(left.second, right.second)+ root->data);
        }
        else if(left.first > right.first){
            return make_pair(left.first+1, left.second+ root->data);
        }
        else{
            return make_pair(right.first+1, right.second+ root->data);
        }
    }
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        return longest_path_sum(root).second;
    }
};