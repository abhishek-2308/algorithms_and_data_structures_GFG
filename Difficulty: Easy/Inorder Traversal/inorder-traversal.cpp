/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        Node* curr= root;
        vector<int> ans;
        while(curr){
            Node* temp= curr->left;;
            if(temp){
                while(temp->right and temp->right!=curr){
                    temp= temp->right;
                }
                if(temp->right==nullptr){
                    temp->right= curr;
                    
                    curr= curr->left;
                }
                else{
                    ans.push_back(curr->data);
                    curr= curr->right;
                    
                }
            }
            else{
                ans.push_back(curr->data);
                curr= curr->right;
            }
            
        }
        return ans;
    }
};