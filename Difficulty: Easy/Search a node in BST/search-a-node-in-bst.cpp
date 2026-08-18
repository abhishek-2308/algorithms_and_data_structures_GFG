/*
Definition for Node
class Node {
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
  public:
    bool search(Node* root, int key) {
        // code here
        while(root){
            if(root->data==key)return 1;
            else if(root->data < key){
                root= root->right;
            }
            else{
                root= root->left;
            }
        }
        return false;
    }
};