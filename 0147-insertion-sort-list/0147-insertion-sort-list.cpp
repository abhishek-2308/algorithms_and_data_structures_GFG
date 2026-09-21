/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* curr= head;
        ListNode* dummy= new ListNode(-1);
        while(curr){
            ListNode* prev= dummy;
            ListNode* next_node= curr->next;
            while(prev  and prev->next and prev->next->val < curr->val){
                prev= prev->next;
            }
            curr->next = prev->next;
            prev->next = curr;

            
            curr = next_node;

        }
        return dummy->next;
    }
};