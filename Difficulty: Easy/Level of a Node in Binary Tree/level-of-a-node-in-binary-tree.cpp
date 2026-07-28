/* Structure of tree node
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
  public:
    int getLevel(struct Node *node, int target) {
        // code here
        queue<pair<Node*, int>> q;
        q.push(make_pair(node, 1));
        while(!q.empty()){
            pair<Node* , int> front= q.front();
            q.pop();
            int level= front.second;
            Node* root= front.first;
            if(root->data==target)return level;
            if(root->left){
                q.push(make_pair(root->left, level+1));
            }
            if(root->right){
                q.push(make_pair(root->right, level+1));
            }
        }
        return 0;
    }
};