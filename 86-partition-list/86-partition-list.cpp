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
        
        ListNode* greaterHeadRef = new ListNode(); // head reference for greater than x nodes list
        ListNode* greater = greaterHeadRef; // node runner for greaterHeadRef
        
        ListNode* lesserHeadRef = new ListNode(); // head reference for less than x nodes list
        ListNode* less = lesserHeadRef; // node runner for lesserHeadRef
        
        while(head != nullptr) {
            if(head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        delete head;
        
        greater->next = nullptr;
        less->next = nullptr;
        
        less->next = greaterHeadRef->next;
        
        return lesserHeadRef->next;
    }
};

// Time Complexity: O(n)