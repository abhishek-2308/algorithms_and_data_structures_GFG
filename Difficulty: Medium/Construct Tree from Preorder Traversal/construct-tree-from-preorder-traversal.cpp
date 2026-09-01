/* Structure of the binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/

class Solution {
    private:
    Node* make_tree(vector<int> &pre, vector<char> &preLN, int &index){
        if(index>= pre.size())return nullptr;
        Node* root= new Node(pre[index]);
        if(preLN[index++]=='L'){
            return root;
        }
        else {
            root->left= make_tree(pre, preLN, index);
            root->right= make_tree(pre, preLN, index);
            return root;
        }
        
        
    }
  public:
    Node* constructTree(vector<int>& pre, vector<char>& preLN) {
        int index=0;
        return make_tree(pre, preLN, index);
    
        
    }
};