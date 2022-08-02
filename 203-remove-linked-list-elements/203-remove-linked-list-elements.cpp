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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) {
            return head;
        }
        
        ListNode* dummy = new ListNode();
        ListNode* runner = dummy;
        
        while(head != nullptr) {
            if(head->val != val) {
                runner->next = head;
                runner = runner->next;
            }
            head = head->next;
        }
        
        runner->next = nullptr;
        
        return dummy->next;
    }
};