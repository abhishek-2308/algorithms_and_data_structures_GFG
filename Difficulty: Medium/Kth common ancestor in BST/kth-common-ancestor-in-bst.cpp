/*Structure of a Tree Node
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
    int kthCommonAncestor(Node *root, int k, int x, int y) {
        
        Node* curr= root;
        vector<int> ancestor;
        while(curr != nullptr){
            ancestor.push_back(curr->data);
            if(curr->data < x and curr->data <y){
                curr= curr->right;
            }
            else if(curr->data > x and curr->data >y){
                curr= curr->left;
            }
            else break;
        }
        int total_ancestor= (int)ancestor.size();
        if(k>total_ancestor)return -1;
        return ancestor[total_ancestor-k];
        
        
    }
};
