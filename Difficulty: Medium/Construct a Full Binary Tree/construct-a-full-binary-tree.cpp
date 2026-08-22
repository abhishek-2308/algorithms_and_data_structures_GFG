/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    private:
    Node* get_ans(vector<int> &pre, vector<int>& preMirror, int &i, int &j){
        Node* root= new Node(pre[i]);
        if(pre[i]==preMirror[j]){
            j--;
            return root;
        }
        
        int curr_root= pre[i];
        i++;
        root->left= get_ans(pre,preMirror, i, j);
        i++;
        root->right= get_ans(pre, preMirror, i,j);
        if(curr_root== preMirror[j]){
            j--;
        }
        return root;
    }
  public:
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        // code here
        int i= 0;
        int j= preMirror.size()-1;
        return get_ans(pre, preMirror, i, j);
    }
};