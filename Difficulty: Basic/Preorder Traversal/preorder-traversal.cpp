/* Structure of Tree Node
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
};*/

class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> ans;
        Node* curr= root;
        while(curr){
            Node* temp= curr->left;
            if(temp){
                
                while(temp->right and temp->right != curr){
                    temp= temp->right;
                }
                if(temp->right== nullptr){
                    ans.push_back(curr->data);
                    temp->right= curr;
                    curr= curr->left;
                }
                else{
                    curr= curr->right;
                }
            }
            else{
                ans.push_back(curr->data);
                curr=  curr->right;
            }
        }
        return ans;
    }
};