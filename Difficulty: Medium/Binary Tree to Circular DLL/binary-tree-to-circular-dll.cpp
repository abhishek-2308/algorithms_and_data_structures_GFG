/* Tree Node Structure
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
Node* prev= nullptr;
Node* head=  nullptr;
  public:
  void get_ans(Node* root){
      if(!root)return;
      get_ans(root->left);
      if(!head){
          head= root;
          prev= root;
      }
      else{
          root->left= prev;
          prev->right= root;
          prev= root;
      }
      get_ans(root->right);
  }
    Node *bTreeToCList(Node *root) {
        get_ans(root);
        head->left= prev;
        prev->right= head;
        return head;
        
    }
};