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
}; */

class Solution {
  public:
    vector<int> merge(Node *r1, Node *r2) {
        // code here
        stack<Node*> st1;
        stack<Node*> st2;
        Node* curr= r1;
        while(curr){
            st1.push(curr);
            curr= curr->left;
        }
        curr= r2;
        while(curr){
            st2.push(curr);
            curr= curr->left;
        }
        vector<int> ans;
        while(!st1.empty() and !st2.empty()){
            Node* top1= nullptr;
            Node* top2= nullptr;
            if(st1.top()->data < st2.top()->data){
                top1= st1.top();
                st1.pop();
            }
            else{
                top2= st2.top();
                st2.pop();
            }
            
            if(top1!=nullptr){
                ans.push_back(top1->data);
                top1= top1->right;
                while(top1){
                    st1.push(top1);
                    top1= top1->left;
                }
            }
            else{
                ans.push_back(top2->data);
                top2= top2->right;
                while(top2){
                    st2.push(top2);
                    top2= top2->left;
                }
            }
        }
        while(!st1.empty()){
            Node* top= st1.top();
            st1.pop();
            
            ans.push_back(top->data);
            top= top->right;
            while(top){
                st1.push(top);
                top= top->left;
            }
            
        }
         while(!st2.empty()){
            Node* top= st2.top();
            st2.pop();
            ans.push_back(top->data);
            top= top->right;
            while(top){
                st2.push(top);
                top= top->left;
            }
            
        }
        
        return ans;
    }
};