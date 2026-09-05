/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
    private:
    int get_count(Node* tree){
        if(!tree)return 0;
        return 1+ get_count(tree->left) + get_count(tree->right);
    }
    bool is_cbt(int count, Node* tree, int left_right){
        if(!tree)return 1;
        if(left_right >= count)return false;
        return is_cbt(count, tree->left, 2*left_right+1) and is_cbt(count, tree->right, 2*left_right+2);
    }
    bool is_lees(Node* tree, int par){
        if(!tree)return 1;
        if(tree->data > par){
            return false;
        }
        return is_lees(tree->left, tree->data) and is_lees(tree->right, tree->data);
    }
  public:
    bool isHeap(Node* tree) {
        // code here
        int count= get_count(tree);
        if(is_cbt(count, tree, 0) and (is_lees(tree, INT_MAX))){
            return 1;
        }return false;
    }
};