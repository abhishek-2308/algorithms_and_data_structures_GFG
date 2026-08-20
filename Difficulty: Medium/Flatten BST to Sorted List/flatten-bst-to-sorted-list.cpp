/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
    private:
    void get_ans(Node* root, Node* &head, Node* &prev){
        if(!root){
            return;
        }
        get_ans(root->left, head, prev);
       if(head==nullptr){
           head= root;
       }
       else{
           prev->right= root;
       }
       root->left= nullptr;
       prev= root;
        get_ans(root->right, head, prev);
        
    }
  public:
    Node *flattenBST(Node *root) {
        // code here
        Node* prev= nullptr;
        Node* head= nullptr;
        get_ans(root, head, prev);
        return head;
    }
};