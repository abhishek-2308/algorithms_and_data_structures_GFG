/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
    private:
    void get_in(Node* root, vector<int> &in){
        if(!root)return;
        get_in(root->left, in);
        in.push_back(root->data);
        get_in(root->right, in);
    }
    void revert_nodes(vector<int> &in, int &index, Node* root){
        if(!root)return;
        revert_nodes(in, index, root->left);
        root->data= in[index++];
        revert_nodes(in, index, root->right);
    }
  public:
    Node* correctBST(Node* root) {
        // code here
        vector<int> in;
        get_in(root, in);
        int first= -1;
        int second= -1;
        int i=1;
        while(i<in.size()){
            if(in[i]<in[i-1]){
                if(first==-1 and second==-1){
                    first=i-1;
                    second=i;
                }
                else{
                    
                    second= i;
                }
            }
            i+=1;
        }
        swap(in[first], in[second]);
        int index=0;
        revert_nodes(in, index, root);
        return root;
        
    }
};