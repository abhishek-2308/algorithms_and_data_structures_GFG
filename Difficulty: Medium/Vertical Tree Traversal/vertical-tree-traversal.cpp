/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        map<int, vector<int>> mp;
        queue<pair<int,Node*>> q;
        q.push(make_pair(0, root));
        mp[0].push_back(root->data);
        while(!q.empty()){
            pair<int, Node*> front= q.front();
            q.pop();
            int left_or_right= front.first;
            Node* node= front.second;
            if(node->left){
                q.push(make_pair(left_or_right-1, node->left));
                mp[left_or_right-1].push_back(node->left->data);
            }
            if(node->right){
                q.push(make_pair(left_or_right+1, node->right));
                mp[left_or_right+1].push_back(node->right->data);
            }
        }
        vector<vector<int>> ans;
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};