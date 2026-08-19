/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
    private:
    Node* get_pre(Node* root){
        while(root and root->right){
            root= root->right;
        }
        return root;
    }
    Node* get_succ(Node* root){
        while(root and root->left){
            root= root->left;
        }
        return root;
    }
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
     Node* pre= nullptr;
     Node* succ=  nullptr;
     Node* curr= root;
     while(curr){
         if(curr->data== key){
             if(curr->left){
                 pre= get_pre(curr->left);
             }
             if(curr->right){
                 succ= get_succ(curr->right);
             }
             break;
         }
         else if(curr->data < key){
             pre= curr;
             curr= curr->right;
         }
         else{
             succ= curr;
             curr= curr->left;
            //  curr= curr->
         }
     }
    //  return vector<int> (pre, succ);
    return {pre, succ};
    }
};