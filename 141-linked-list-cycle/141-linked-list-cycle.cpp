/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* turtle = head;
        ListNode* hare = head;
        
        while(hare->next->next != nullptr) {
            turtle = turtle->next;
            hare = hare->next->next;
                
            if(hare == turtle) {
                return true;
            }
            if(hare->next == nullptr) {
                return false;
            }
        }
        
        return false;
    }
};