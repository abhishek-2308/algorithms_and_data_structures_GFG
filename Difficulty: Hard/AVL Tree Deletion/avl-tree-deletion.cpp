/* Structure of AVL Tree Node
class Node {
  public:
    int data, height;
    Node *left, *right;

    Node(int x) {
        data = x;
        height = 1;
        left = right = nullptr;
    }
}; */
class Solution {
    private:
    Node* get_mini_from_right(Node* root){
        while(root->left){
            root= root->left;
        }
        return root;
    }
    int get_height(Node* root){
        if(!root)return 0;
        else {
            return root->height;
        }
    }
    int get_balance(Node* root){
        return get_height(root->left)- get_height(root->right);
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
    Node* right_rotation(Node* root){
        Node* child= root->left;
        Node* childRight= child->right;
        child->right= root;
        root->left= childRight;
        root->height= 1+ max(get_height(root->left), get_height(root->right));
        child->height= 1+ max(get_height(child->left), get_height(child->right));
        return child;
    }
    public:
    Node* deleteNode(Node* root, int key) {
    
        if(root->data < key){
            root->right= deleteNode(root->right, key);
        }
        else if(root->data > key){
            root->left= deleteNode(root->left, key);
        }
        else{
            if(!root->left and !root->right){
                delete(root);
                return nullptr;
            }
            else if(!root->left and root->right){
                Node* temp= root->right;
                delete(root);
                return temp;
            }
            else if(!root->right and root->left){
                Node* temp= root->left;
                delete(root);
                return temp;
            }
            else if(root->left and root->right){
               Node* node= get_mini_from_right(root->right);
               root->data= node->data;
               root->right= deleteNode(root->right, node->data);
            }
        }
            root->height= 1+ max(get_height(root->left), get_height(root->right));
            int balance= get_balance(root);
            if (balance > 1 && get_balance(root->left) >= 0) {
                return right_rotation(root);
            }

            if (balance > 1 && get_balance(root->left) < 0) {
                root->left = left_rotation(root->left);
                return right_rotation(root);
            }

            if (balance < -1 && get_balance(root->right) <= 0) {
                return left_rotation(root);
            }

            if (balance < -1 && get_balance(root->right) > 0) {
                root->right = right_rotation(root->right);
                return left_rotation(root);
            }
            return root;
        }
    
};