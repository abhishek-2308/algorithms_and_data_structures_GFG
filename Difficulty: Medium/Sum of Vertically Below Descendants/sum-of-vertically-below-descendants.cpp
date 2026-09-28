/* BST Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
    private:
    void get_ans(Node* root, int &target, int &sum, int ver, int lev, bool &found){
        if(!root)return;
        if(ver==lev)sum+= root->data;
       if(root->data== target){
           found= 1;
           ver= lev;
       }
        get_ans(root->left, target, sum, ver, lev-1, found);
        get_ans(root->right, target, sum, ver, lev+1, found);
        
    }
  public:
    int verticalSum(Node *root, int target) {
        // code here
        int sum=0;;
        int ver= 1e9;
        bool found= false;
        get_ans(root, target, sum, ver, 0, found);
        if(!found)return -1;
        
        return sum;
        
    }
};