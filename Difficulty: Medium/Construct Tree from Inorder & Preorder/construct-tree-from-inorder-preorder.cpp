/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
    private:
    Node* build_from_inorder_and_preorder(vector<int> &inorder, vector<int> &preorder, int &index, int startingIndex, int endingIndex, unordered_map<int, int> &mp){
        if(index>=inorder.size())return nullptr;
        if(startingIndex>endingIndex)return nullptr;
        int mid= mp[preorder[index]];
        Node* root= new Node(preorder[index++]);
        root->left= build_from_inorder_and_preorder(inorder, preorder, index, startingIndex, mid-1, mp);
        root->right= build_from_inorder_and_preorder(inorder, preorder, index, mid+1, endingIndex, mp);
        return root;
       
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
      unordered_map<int, int> mp;
      for(int i=0; i<inorder.size(); i++){
          mp[inorder[i]]=i;
      }
      int index=0;
      return build_from_inorder_and_preorder(inorder, preorder, index, 0, inorder.size()-1, mp);
    }
};