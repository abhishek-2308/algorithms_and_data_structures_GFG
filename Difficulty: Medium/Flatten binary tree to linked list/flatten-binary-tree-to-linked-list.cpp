class Solution {
  public:
    void flatten(Node *root) {
        // code here
        Node* curr= root;
        while(curr){
            Node* temp= curr->left;
            if(temp){
                while(temp->right != nullptr){
                    temp= temp->right;
                }
                if(temp->right== nullptr){
                    temp->right= curr->right;
                }
                curr->right= curr->left;
                curr->left= nullptr;
                curr= curr->right;
            }
            else{
                curr= curr->right;
            }
        }
    }
};