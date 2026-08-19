/* Structure of a Binary Search Tree node
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
    private:
    Node* get_min_or_Max_Node_From_Left_right(Node* root){
        if(!root)return nullptr;
        Node* curr= root;
        while(curr and curr->right){
            curr= curr->right;
        }
        return curr;
    }
    Node* delete_node_from_Tree(Node* root, int x){
        if(!root){
            return root;
        }
        if(root->data==x){
            if(root->left==nullptr and root->right==nullptr){
               return nullptr; 
            }
            else if(root->left and !root->right){
                // Node* temp= 
                return root->left;
            }
            else if(!root->left and root->right){
                return root->right;
            }
            //both tthe exist
            
              Node* temp_node= get_min_or_Max_Node_From_Left_right(root->left);
              root->data= temp_node->data;
              root->left= delete_node_from_Tree(root->left, temp_node->data);
            return root;
        }
        else if(root->data <x){
            root->right= delete_node_from_Tree(root->right, x);
            return root;
        }
        else{
            root->left= delete_node_from_Tree(root->left, x);
            return root;
        }
        return root;
    }
  public:
    Node* delNode(Node* root, int x) {
        // code here
        return delete_node_from_Tree(root, x);
    }
};