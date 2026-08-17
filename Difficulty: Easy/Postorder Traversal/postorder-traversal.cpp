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
    vector<int> postOrder(Node* root) {
        // code here
        vector<int> ans;
        Node* curr= root;
        while(curr){
            Node* temp= curr->right;
            if(temp){
                while(temp->left and temp->left != curr){
                    temp= temp->left;
                }
                if(temp->left==nullptr){
                    temp->left= curr;
                    ans.push_back(curr->data);
                    curr= curr->right;
                    
                    
                }
                else{
                    curr= curr->left;
                }
            }
            else{
                ans.push_back(curr->data);
                curr= curr->left;
            }
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};