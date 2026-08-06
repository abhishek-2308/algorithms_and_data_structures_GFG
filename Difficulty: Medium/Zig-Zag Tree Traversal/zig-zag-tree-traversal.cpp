/* Structure of Binary Tree Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int> ans;
        bool flag= false;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size= q.size();
            vector<int> temp(size);
            for(int i=0; i<size; i++){
                int index= flag ? size-i-1: i;
                Node* front= q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                temp[index]= front->data;
               
            }
            for(int i=0; i<temp.size(); i++){
                ans.push_back(temp[i]);
            }
            flag= !flag;
        }
        return ans;
    }
};