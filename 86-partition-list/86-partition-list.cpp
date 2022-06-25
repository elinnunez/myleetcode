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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* greaterHeadRef = new ListNode();
        ListNode* greater = greaterHeadRef;
        ListNode* lesserHeadRef = new ListNode();
        ListNode* less = lesserHeadRef;
        
        ListNode* cur = head;
        
        while(cur != nullptr) {
            if(cur->val < x) {
                less->next = cur;
                less = less->next;
            } else {
                greater->next = cur;
                greater = greater->next;
            }
            cur = cur->next;
        }
        
        greater->next = nullptr;
        less->next = nullptr;
        
        less->next = greaterHeadRef->next;
        
        return lesserHeadRef->next;
    }
};