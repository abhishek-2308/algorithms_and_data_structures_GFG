/* The Node structure is
class Node {
public:
    int data;
    Node* left;
    Node* right;

};
}; */

class Solution {
  public:
    int maxDepth(Node *root) {
        // code here
        int  maxi= 1;
        queue<pair<Node*, int>> q;
        q.push({root, 1});
        while(!q.empty()){
            auto front= q.front();
            q.pop();
            Node* node= front.first;
            int level= front.second;
            maxi= max(maxi, level);
            if(node->left){
                q.push(make_pair(node->left, level+1));
            }
            if(node->right){
                q.push(make_pair(node->right, level+1));
            }
            
        }
        return maxi;
    }
};
