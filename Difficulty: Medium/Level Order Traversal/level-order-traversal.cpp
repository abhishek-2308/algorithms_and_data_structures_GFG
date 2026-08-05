/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // code here
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* node= q.front();
            q.pop();
            ans.emplace_back(node->data);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        return ans;
    }
};