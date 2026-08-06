/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
    private:
    bool get_ans(Node* r1, Node* r2){
        if(!r1 and r2)return false;
        if(r1 and !r2)return false;
        if(!r1 and !r2)return true;
        if(r1->data !=  r2->data)return false;
        bool left= get_ans(r1->left, r2->left);
        bool right= get_ans(r1->right, r2->right);
        return left and right;
    }
  public:
    bool isIdentical(Node* r1, Node* r2) {
        // code here
        return get_ans(r1, r2);
    }
};