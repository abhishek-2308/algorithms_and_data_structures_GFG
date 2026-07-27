/*
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
};
*/

class Solution {
    private:
    void callForTheLeftView(int level, vector<int> &ans, Node* root){
     if(root==nullptr){
         return;
     }
     if(level==ans.size()){
         ans.push_back(root->data);
     }
     callForTheLeftView(level+1, ans, root->left);
     callForTheLeftView(level+1, ans, root->right);
     
 }
  public:
    vector<int> leftView(Node *root) {
        // code here
        if(root==nullptr){
        return {};
    }
  int level=0;
  vector<int> ans;
  callForTheLeftView(level, ans, root);
  return ans;
    }
};