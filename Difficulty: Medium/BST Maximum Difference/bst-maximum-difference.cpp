class Solution {
private:

    bool findTarget(Node* root, int target, Node*& node, int& s1) {

        if (root == nullptr)
            return false;

        if (root->data == target) {
            node = root;
            return true;
        }

        if (findTarget(root->left, target, node, s1)) {
            s1 += root->data;
            return true;
        }

        if (findTarget(root->right, target, node, s1)) {
            s1 += root->data;
            return true;
        }

        return false;
    }

    int minLeafSum(Node* root) {

        if (root == nullptr)
            return INT_MAX;

        if (root->left == nullptr && root->right == nullptr)
            return root->data;

        return root->data + min(
            minLeafSum(root->left),
            minLeafSum(root->right)
        );
    }

public:

    int maxDifferenceBST(Node* root, int target) {

        Node* targetNode = nullptr;
        int s1 = 0;

        if (!findTarget(root, target, targetNode, s1))
            return -1;

        // Target itself is a leaf
        if (targetNode->left == nullptr &&
            targetNode->right == nullptr) {
            return s1;
        }

        int s2 = min(
            minLeafSum(targetNode->left),
            minLeafSum(targetNode->right)
        );

        return s1 - s2;
    }
};