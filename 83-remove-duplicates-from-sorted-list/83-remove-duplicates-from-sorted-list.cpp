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
    // Works for sorted and unsorted linked lists
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* cur = head;
        while(cur != nullptr) {
            ListNode* temp = cur->next; // to loop through list
            ListNode* prev = cur; // hold reference for next non dup of cur->val
            ListNode* prevHead = prev; // hold reference for head of prev list
            while(temp != nullptr) {
                if(temp->val == cur->val) {
                    prev->next = temp->next;
                    temp = prev;
                } else {
                    prev = prev->next;
                }
                temp = temp->next;
            }
            delete temp;
            cur->next = prevHead->next;
            cur = cur->next;
        }
        delete cur;
        
        return head;
    }
};