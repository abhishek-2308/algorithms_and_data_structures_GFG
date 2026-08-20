/* Structure of a Binary Search Tree node
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
    Node* findLCA(Node* root, Node* n1, Node* n2) {
        // code here
        Node* curr= root;
        while(curr){
            if(curr->data < n1->data and curr->data < n2->data){
                curr= curr->right;
            }
            else if(curr->data > n1->data and curr-> data > n2->data){
                curr= curr->left;
            }
           else break;
        }
        return curr;
    }
};