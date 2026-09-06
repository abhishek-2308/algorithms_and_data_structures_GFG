/* Binary Tree Node Structure
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
    void get_inorder(Node* root, vector<int> &in){
        if(!root)return;
        get_inorder(root->left, in);
        in.push_back(root->data);
        get_inorder(root->right, in);
    }
    void pre_order(Node* root, vector<int> &in,  int &index){
        if(!root)return;
        root->data = in[index--];
        pre_order(root->right, in, index);
        pre_order(root->left, in, index);
        
        
    }
  public:
    void convertToMaxHeap(Node* root) {
        // code here
        vector<int> in;
        get_inorder(root, in);
        int index=in.size()-1;
        pre_order(root, in, index);
    }
};




// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

// class Solution {
    
//     private:
//     void convertIntoMAxHeap(Node* root, vector<int> &in, int &i){
//         if(!root){
//             return;
//         }
//         root->data= in[i--];
//         convertIntoMAxHeap(root->right, in, i);
//         convertIntoMAxHeap(root->left, in, i);
//     }
//     void takeInorder(Node* root, vector<int> &in){
//         if(!root){
//             return;
//         }
//         takeInorder(root->left, in);
//         in.push_back(root->data);
//         takeInorder(root->right, in);
//     }
//   public:
//     void convertToMaxHeap(Node* root) {
//         vector<int> in;
//         takeInorder(root, in);
//         int i=in.size()-1;
//         //root, right, left
//         convertIntoMAxHeap(root, in, i);
        
//     }
// };
