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
    Node* get_ans(Node* root, int key){
       
        if(!root){
            return new Node(key);
        }
        
        if(root->data== key)return root;
        if(root->data < key){
            root->right= get_ans(root->right, key);
            return root;
        }
        else{
            root->left= get_ans(root->left, key);
            return root;
        }
    }
  public:
    Node* insert(Node* root, int key) {
        // code  here
        return get_ans(root, key);
    }
};