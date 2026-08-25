/* Linked List Node Structure
class NodeLL {
  public:
    int data;
    NodeLL *next;

    NodeLL(int x) {
        data = x;
        next = nullptr;
    }
};

Binary Tree Node Structure
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
    int index=0;
    void get_ans(vector<Node*> &arr){
        while(index< arr.size()){
            int leftIndex= 2*index+1;
            int rightIndex= 2*index+2;
            if(leftIndex < arr.size()){
                arr[index]->left= arr[leftIndex];
            }
            if(rightIndex <arr.size()){
                arr[index]->right= arr[rightIndex];
            }
            index+=1;
        }
    }
  public:
    Node *linkedListToBinaryTree(NodeLL *head) {
        // code here
     vector<Node*> vec;
     NodeLL* curr= head;
     while(curr){
         Node* newNode= new Node(curr->data);
         vec.push_back(newNode);
         curr= curr->next;
     }
     get_ans(vec);
     return vec[0];
     
    }
};