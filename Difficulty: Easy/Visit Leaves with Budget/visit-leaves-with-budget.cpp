/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    int getCount(Node *root, int k) {
        // code here
        queue<pair<Node*, int>>q;
        //denotes the root, level
        q.push(make_pair(root, 1));
        int ans=0;
        while(!q.empty()){
            pair<Node*, int> front= q.front();
            q.pop();
            Node* node= front.first;
            int level= front.second;
            if(node->left==  nullptr and node->right==nullptr and k>=level){
                k= k-level;
                ans+=1;
            }
            if(node->left){
                q.push(make_pair(node->left, level+1));
                
            }
            if(node->right){
                q.push(make_pair(node->right, level+1));
            }
        }
        return ans;
    }
};