/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    private:
    int count_total(Node* root, int &k, unordered_map<int, int> &mp, int sum){
        if(!root)return 0;
        sum+=root->data;
        int count= mp[sum- k];
        mp[sum]++;
        count= count+ count_total(root->left, k, mp, sum);
        count= count+ count_total(root->right, k, mp, sum);
        mp[sum]--;
        if(mp[sum]==0){
            mp.erase(sum);
        }
        return count;
    }
  public:
    int countAllPaths(Node *root, int k) {
        // code here
        unordered_map<int, int> mp;
        mp[0]=1;
        return count_total(root, k, mp, 0);
    }
};