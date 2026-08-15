/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
    private:
    Node* make_tree(vector<int> inorder, vector<int> &postorder, unordered_map<int, int> &mp, int &index, int startingIndex, int endingIndex){
        if(index<0)return nullptr;
        if(startingIndex>endingIndex)return nullptr;
        Node* root= new Node(postorder[index]);
        int find= mp[postorder[index--]];
        root->right= make_tree(inorder,postorder,mp, index,  find+1, endingIndex);
        root->left= make_tree(inorder, postorder, mp, index, startingIndex, find-1);
        return root;
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        unordered_map<int, int> mp;
        int i=0;
        while(i<inorder.size()){
            mp[inorder[i]]=i;
            i++;
        }
        i= postorder.size()-1;
        return make_tree(inorder, postorder, mp, i, 0, postorder.size()-1);
    }
};