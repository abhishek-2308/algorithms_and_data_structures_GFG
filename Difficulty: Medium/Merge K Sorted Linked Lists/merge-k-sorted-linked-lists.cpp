/* Linked List Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
    private:
    Node* merge(Node* n1, Node* n2){
        if(!n2)return n1;
        if(!n1)return n2;
        if(n1->data < n2->data){
             n1->next= merge(n1->next, n2);
             return n1;
        }
         n2->next= merge(n1, n2->next);
         return n2;
    }
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        if(arr.size()==1){
            return arr[0];
        }
        Node* x= arr[0];
        for(int i=1; i<arr.size(); i+=1){
            x= merge(arr[i], x);
        }
        return x;
        
    }
};