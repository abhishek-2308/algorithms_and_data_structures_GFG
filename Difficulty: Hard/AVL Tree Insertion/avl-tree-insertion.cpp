/* Structure of AVL Tree Node
class Node {
public:
    int data;
    int height;
    Node *left, *right;
    Node(int x) {
        data = x;
        height = 1;
        left = right = nullptr;
    }
}; */

class Solution {
    private:
    int get_height(Node* root){
        if(!root)return 0;
        return root->height;
    }
    int get_balance(Node* root){
        if(!root)return 0;
       return get_height(root->left)- get_height(root->right);
    }
    Node* right_rotation(Node* root){
        Node* child= root->left;
        Node* childRight= child->right;
        child->right= root;
        root->left= childRight;
        root->height= 1+ max(get_height(root->left), get_height(root->right));
        child->height= 1+ max(get_height(child->left), get_height(child->right));
        return child;
    }
    Node* left_rotation(Node* root){
        Node* child= root->right;
        Node* childLeft= child->left;
        child->left= root;
        root->right= childLeft;
        root->height= 1+ max(get_height(root->left), get_height(root->right));
        child->height= 1+ max(get_height(child->left), get_height(child->right));
        return child;
    }
  public:
    Node* insertToAVL(Node* root, int key) {
        if(!root){
            return new Node(key);
        }
        else if(key < root->data){
            root->left = insertToAVL(root->left, key);
        }
        else if(key > root->data){
            root->right = insertToAVL(root->right, key);
        }
        else{
            return root;
        }
        root->height=1+ max(get_height(root->left), get_height(root->right));
        
        int balance= get_balance(root);
        if(balance > 1 and key<root->left->data){
            return right_rotation(root);
        }
        else if(balance < -1 and key>root->right->data){
            return left_rotation(root);
        }
        else if (balance > 1 and key > root->left->data){
            root->left= left_rotation(root->left);
            return right_rotation(root);
        }
        else if(balance < -1 and root->right->data > key){
            root->right= right_rotation(root->right);
            return left_rotation(root);
        }
        else return root;
        
           
    }
};