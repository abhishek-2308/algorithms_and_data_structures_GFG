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
};
*/
class Solution {
    private:
    void get_the_maximum_no_of_nodes(Node* root, map<int, int> &store_the_nodes_at_each_level, int level){
        if(!root)return;
        store_the_nodes_at_each_level[level]++;
        get_the_maximum_no_of_nodes(root->left, store_the_nodes_at_each_level, level+1);
        get_the_maximum_no_of_nodes(root->right, store_the_nodes_at_each_level, level+1);
        
    }
  public:
    int maxNodeLevel(Node *root) {
        // code here
        map<int, int> store_the_nodes_at_each_level;
        get_the_maximum_no_of_nodes(root, store_the_nodes_at_each_level, 0);
        int maxi= 0;
        int level_ans=0;
        for(auto i: store_the_nodes_at_each_level){
            if(maxi<i.second){
                maxi= i.second;
                level_ans= i.first;
            }
        }
        return level_ans;
        
    }
};