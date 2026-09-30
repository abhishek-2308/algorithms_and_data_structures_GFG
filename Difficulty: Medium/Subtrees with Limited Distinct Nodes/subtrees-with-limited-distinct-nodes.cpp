/* structure of binary tree node
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
    private:
    unordered_set<int> get_ans(Node* root, int k, int &count){
        if(!root)return unordered_set<int> ();
        unordered_set<int> left= get_ans(root->left, k, count);
        unordered_set<int> right= get_ans(root->right, k, count);
        unordered_set<int> st;
        st.insert(left.begin(), left.end());
        st.insert(right.begin(), right.end());
        st.insert(root->data);
        if((int)st.size() <= k){
            count+=1;
        }
        return st;
    }
  public:
    int goodSubtrees(Node *root, int k) {
        // code here
        int count= 0;
        get_ans(root, k, count);
        return count;
    }
};