/* Structure of linked list Node
class Node {
  public:
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
    Node* insertionSort(Node* head) {
        
      Node* curr= head;
      Node* dummy= new Node(-1);
      while(curr){
          Node* prev= dummy;
          Node* next_node= curr->next;
          while(prev and prev->next and prev->next->val < curr->val){
              prev= prev->next;
          }
          curr->next= prev->next;
          prev->next= curr;
          curr= next_node;
          
      }
      return dummy->next;
    }
};


